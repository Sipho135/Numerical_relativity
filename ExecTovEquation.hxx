#include <vector>
#include <cmath>
class ExecTovEquation{
    private:
        int LastIndex;
    
    public:
        int ExecTOVxCoord(Storage &storage){
            for (int i = 1; i < storage.getSize(); ++i) {
                std::vector<double> y0 = {storage.getMass(i - 1), storage.getPressure(i - 1), storage.getNu(i - 1), storage.getRadius(i - 1)};
                std::vector<double> y_new = rk4_solver(tov_equations_x, y0, Var::h, storage.getX(i - 1), storage.getE(i - 1));

                if (std::isnan(y_new[1])) {
                    LastIndex = i;
                    break;
                }

                storage.updateValues(i, y_new[0], y_new[1], y_new[2], y_new[3],
                                    -(log(1 - 2 * y_new[0] / y_new[3])) / 2,
                                    std::pow(y_new[1] / Var::K, 1.0 / Var::Gamma) + y_new[1] / (Var::Gamma - 1),
                                    0.0, 0.0, storage.getX(i - 1) + Var::h);
            }

            updateAdditionalValues(storage);

            return LastIndex;
        }


        int ExecTOVrCoord(Storage &storage) {

            for (int i = 1; i < storage.getSize(); ++i) {
                std::vector<double> y0 = {storage.getMass(i - 1), storage.getPressure(i - 1), storage.getNu(i - 1)};
                std::vector<double> y_new = rk4_solver(tov_equations_r, y0, Var::h, storage.getRadius(i - 1), storage.getE(i - 1));

                if (y_new[1] < 0.0) {
                    LastIndex = i;
                    break;
                }
                double r =  storage.getRadius(i - 1) + Var::h;
                storage.updateValues(i, y_new[0], y_new[1], y_new[2], r,
                                    -(log(1 - 2 * y_new[0] / r)) / 2, std::pow(y_new[1] / Var::K, 1.0 / Var::Gamma) + y_new[1] / (Var::Gamma - 1), 0.0, 0.0, 0.0);
            }

            updateAdditionalValues(storage);
            return LastIndex;
        }

        void updateAdditionalValues(Storage& storage) {
            double C = (log(1 - 2 * storage.getMass(LastIndex - 1) / storage.getRadius(LastIndex - 1))) / 2 - storage.getNu(LastIndex - 1);
            for (int i = 0; i < LastIndex; i++) {
                double r = storage.getRadius(i);
                double m = storage.getMass(i);
                double P = storage.getPressure(i);
                double updatedNu = storage.getNu(i) + C;
                double dnudr = (m + 4 * M_PI * std::pow(r, 3) * P) / (r * (r - 2 * m));
                double dmdr = 4 * M_PI * std::pow(r, 2) * (std::pow(P / Var::K, 1.0 / Var::Gamma) + P / (Var::Gamma - 1));
                double dLambdadr = (dmdr * r - m) / (r * (r - 2 * m));
                storage.updateValues(i, m, P, updatedNu, r, storage.getLambda(i), storage.getE(i), dnudr, dLambdadr, (LastIndex == i) ? storage.getX(i) : 0.0);
            }
        }
};
