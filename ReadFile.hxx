#ifndef READFILE_HXX
#define READFILE_HXX

#include <fstream>
#include <string>
#include <vector>

class ReadFile {
private:
    std::string filename_;
    std::ifstream file_;

public:
    ReadFile(const std::string& filename) : filename_(filename) {
        file_.open(filename_);
        if (!file_.is_open()) {
            std::cerr << "Unable to open file: " << filename_ << "\n";
        }
    }

    ~ReadFile() {
        if (file_.is_open()) {
            file_.close();
        }
    }

    // Function to read data from the file into a vector of strings
    std::vector<double> readLines() {
        std::vector<double> inputValues;
        std::string line;
        while (std::getline(file_, line)) {
            std::istringstream iss(line);
            double value;
            if (iss >> value) {
                inputValues.push_back(value);
            }
        }
        return inputValues;
    }


};

#endif // READFILE_HXX
