
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <thread>
#include <sstream>
#include <time.h>
#include "tov_eq.hxx"
#include "rk4.hxx"
#include "unit_storage.hxx"
#include "OutPutFile.hxx"
#include "ExecTovEquation.hxx"
#include "ReadFile.hxx"


constexpr double EPSILON = 1e-20;

int main(int argc, char *argv[]) {
	Storage storage;
	ExecTovEquation tovEquation;
	OutPutFile outputFile;
	ReadFile fileReader(argv[1]);


	std::vector<double> inputValues = fileReader.readLines();

    for(int i = 0; i < inputValues.size(); i++){
		double rho_c = inputValues[i];		//: km^{-2} 
		double P_c = Var::K * std::pow(rho_c, Var::Gamma);
		std::cout <<rho_c<< std::endl;
		storage.updateValues(0, 0.0, P_c, 0.0, EPSILON, -(log(1 - 2 * 0.0 / EPSILON)) / 2, std::pow(P_c / Var::K, 1.0 / Var::Gamma) + P_c / (Var::Gamma - 1), 0.0, 0.0, EPSILON);
		int LastIndex1 = tovEquation.ExecTOVxCoord(storage);
		outputFile.coordinateOutPut(i, LastIndex1, storage, "x");
		outputFile.coordinateOutPut2(i, LastIndex1, storage, "x");
		int LastIndex2 = tovEquation.ExecTOVrCoord(storage);
		outputFile.coordinateOutPut(i, LastIndex2, storage, "r");
		outputFile.coordinateOutPut2(i, LastIndex2, storage, "r");
	
	}

    return 0;
}
