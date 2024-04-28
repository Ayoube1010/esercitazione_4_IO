#include "utils.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

namespace financeLibrary{

bool ImportData(const std::string& inputFilePath, double& S, size_t& n, double*& w, double*& r) {
    std::ifstream file(inputFilePath);
    if (file.fail()) {
        std::cerr << "file open failed" << std::endl;
        return false;
    }

    std::string weight;
    std::string rate;
    std::string line;
    std::string inutile;
    int i = 1;
    std::istringstream dabliu;
    std::istringstream erre;

    while (!file.eof()) {
        if (i == 1) {
            getline(file, inutile, ';');
            getline(file, line);
            std::istringstream esse(line);
            esse >> S;
        } else if (i == 2) {
            getline(file, inutile, ';');
            getline(file, line);
            std::istringstream enne(line);
            enne >> n;
            w = new double[n];
            r = new double[n];
        } else if (i == 3) {
            getline(file, inutile);
        } else {
            getline(file, weight, ';');
            getline(file, rate);
            dabliu.str(weight);
            erre.str(rate);
            dabliu.clear();
            erre.clear();
            dabliu >> w[i - 4];
            erre >> r[i - 4];
        }
        i = i + 1;
    }

    file.close();
    return true;
}

void ComputeRateOfReturn(const double& S, const size_t& n, const double* const& w, const double* const& r, double& rateOfReturn, double& V) {
    V = 0;
    for (unsigned int i = 0; i < n; i++) {
        V += (1 + r[i]) * S * w[i];
    }
    rateOfReturn = (V / S) - 1;
}

void ExportData(std::ostream& out, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& rateOfReturn, const double& V) {
    out << std::fixed << std::showpoint << std::setprecision(2) << "S = " << S << ", n = " << n << std::endl;
    out << "w = " << ArrayToString(n, w) << std::endl;
    out << "r = " << ArrayToString(n, r) << std::endl;
    out << std::fixed << std::showpoint << std::setprecision(4) << "Rate of return of the portfolio: " << rateOfReturn << std::endl;
    out << std::fixed << std::showpoint << std::setprecision(2) << "V: " << V << std::endl;
}

std::string ArrayToString(const size_t& n, const double* const& v) {
    std::ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]";
    return toString.str();
}
}
