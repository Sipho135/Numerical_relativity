#include <cmath>
#include <vector>

namespace Var{
	const double K = 217.858;		//: km^2
	constexpr double R = 65;			//: km
	const double Gamma = 2.0;
	constexpr double h = 5e-5;
	double rho_c = 5.87e-4;		//: km^{-2} 
	double P_c = K * std::pow(rho_c, Gamma);
    constexpr int num_points = static_cast<int>(std::ceil(R / h)) + 1;
		

}

class Storage {
private:
    std::vector<double> radii;
    std::vector<double> masses;
    std::vector<double> pressures;
    std::vector<double> nu;
    std::vector<double> dnudr;
    std::vector<double> e;
    std::vector<double> Lambda;
    std::vector<double> dLambdadr;
    std::vector<double> x;
public:
    Storage(){
        // Initialize arrays with num_points
        radii.resize(Var::num_points);
        masses.resize(Var::num_points);
        pressures.resize(Var::num_points);
        nu.resize(Var::num_points);
        dnudr.resize(Var::num_points);
        e.resize(Var::num_points);
        Lambda.resize(Var::num_points);
        dLambdadr.resize(Var::num_points);
        x.resize(Var::num_points);
    }

    ~Storage(){
    
    }

    void updateValues(int index, double mass, double pressure, double nuValue, double radius, double lambdaValue, double eValue, double dnuDrValue, double dLambdaDrValue, double xPos) {
        // Update values at the given index
        radii[index] = radius;
        masses[index] = mass;
        pressures[index] = pressure;
        nu[index] = nuValue;
        dnudr[index] = dnuDrValue;
        e[index] = eValue;
        Lambda[index] = lambdaValue;
        dLambdadr[index] = dLambdaDrValue;
        x[index] = xPos;
    }

    // Functions to get values
    double getRadius(int index) const{
        return radii[index];
    }

    double getMass(int index) const{
        return masses[index];
    }

    double getPressure(int index) const{
		return pressures[index];
	}

	double getNu(int index) const{
		return nu[index];
	}

	double getDnuDr(int index) const{
		return dnudr[index];
	}

	double getE(int index) const{
		return e[index];
	}

	double getLambda(int index) const{
		return Lambda[index];
	}

	double getDLambdaDr(int index) const{
		return dLambdadr[index];
	}

	double getX(int index) const{
		return x[index];
	}

    int getSize() const {
        return radii.size();
    }
};
