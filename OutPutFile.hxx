#include <iostream>
#include <fstream>
#include <iomanip>

class OutPutFile {
    public:
        void coordinateOutPut(int i, int LastIndex, Storage& storage, const std::string& coordinateType) {
            std::string filePath = "Data folder/" + coordinateType + "_coordinate/solution_" + std::to_string(i) + ".dat";
            std::ofstream file(filePath);
            file << std::setprecision(20) << std::fixed;
            
            for (int idx = 0; idx < LastIndex; ++idx) {
                double Cs = sqrt(Var::Gamma * storage.getPressure(idx) / (storage.getE(idx) + storage.getPressure(idx)));
                if (coordinateType == "x") {
                    file << storage.getX(idx) << "\t";
                } else if (coordinateType == "r") {
                    file << storage.getRadius(idx) << "\t";
                }
                
                file << storage.getRadius(idx) << "\t" << storage.getE(idx) << "\t" << storage.getPressure(idx) << "\t"
                    << storage.getLambda(idx) << "\t" << storage.getNu(idx) << "\t" << storage.getDnuDr(idx) << "\t"
                    << storage.getDLambdaDr(idx) << "\t" << Cs << std::endl;
            }
            file.close();
        }

        void coordinateOutPut2(int i , int LastIndex, Storage& storage, const std::string& coordinateType){
            std::string filePath = "Data folder/" + coordinateType + "_Properties/solution_" + std::to_string(i) + ".dat";
            std::ofstream file(filePath);
            file << std::setprecision(20) << std::fixed;
            
            for (int idx = 0; idx < LastIndex; ++idx) {
                double Cs = sqrt(Var::Gamma * storage.getPressure(idx) / (storage.getE(idx) + storage.getPressure(idx)));
                if (coordinateType == "x") {
                    file << storage.getX(idx) << "\t";
                } else if (coordinateType == "r") {
                    file << storage.getRadius(idx) << "\t";
                }
                
                file << storage.getE(idx) << "\t" << storage.getMass(idx) << "\t" << storage.getPressure(idx) << "\t" << Cs << std::endl;
            }
            file.close();
        }
};
