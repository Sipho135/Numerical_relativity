#include <vector>
template <typename T> 
std::vector<T> rk4_solver(std::vector<T> (*func)(const std::vector<T>&, double, double), const std::vector<T>& y0, double h, double x, double e){
    
	int n = y0.size(); // Get the size of the input vector

    // Calculate k1, k2, k3, and k4
    std::vector<T> k1 = func(y0, x, e);
    std::vector<T> y_temp = y0;
    for (int i = 0; i < n; i++) {
        y_temp[i] = y0[i] + h * k1[i] / 2;
    }
    std::vector<T> k2 = func(y_temp, x + h / 2, e);
    for (int i = 0; i < n; i++) {
        y_temp[i] = y0[i] + h * k2[i] / 2;
    }
    std::vector<T> k3 = func(y_temp, x + h / 2, e);
    for (int i = 0; i < n; i++) {
        y_temp[i] = y0[i] + h * k3[i] / 2;
    }
    std::vector<T> k4 = func(y_temp, x + h, e);

    // Calculate the new values for y
    std::vector<T> y_new(n);
    for (int i = 0; i < n; i++) {
        y_new[i] = y0[i] + (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) * h / 6;
    }

    return y_new;
}
