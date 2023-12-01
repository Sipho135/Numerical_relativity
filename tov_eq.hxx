#include <vector>
#include <cmath>

std::vector<double> tov_equations_x(const std::vector<double>& y, double x, double e) {
    double m = y[0];
    double P = y[1];
    double nu = y[2];
    double r = y[3];
    double Gamma = 2.0;
    double Cs = sqrt(Gamma * P / (e + P));
    double dPdx = Cs * (-(e + P) * (m + 4 * M_PI * std::pow(r, 3) * P) / (r * (r - 2 * m)));
    double dmdx = Cs * (4 * M_PI * std::pow(r, 2) * e);
    double dnudx = Cs * ((m + 4 * M_PI * std::pow(r, 3) * P) / (r * (r - 2 * m)));
    double drdx = Cs;

    return { dmdx, dPdx, dnudx, drdx };
}

std::vector<double> tov_equations_r(const std::vector<double>& y, double r, double e) {
    double m = y[0];
    double P = y[1];
    double nu = y[2];
    double dPdr = -(e + P) * (m + 4 * M_PI * std::pow(r, 3) * P) / (r * (r - 2 * m));
    double dmdr = 4 * M_PI * std::pow(r, 2) * e;
    double dnudr = (m + 4 * M_PI * std::pow(r, 3) * P) / (r * (r - 2 * m));

    return { dmdr, dPdr, dnudr};
}
