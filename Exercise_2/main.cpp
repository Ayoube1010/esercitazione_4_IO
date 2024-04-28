#include "utils.hpp"
#include <iostream>
#include <fstream>

int main() {
    std::string inputFileName = "./data.csv";
    double S = 0.0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;

    if (!financeLibrary::ImportData(inputFileName, S, n, w, r)) {
        std::cerr << "Something went wrong with import" << std::endl;
        return -1;
    }

    // Compute the rate of return of the portfolio and the final wealth V
    double rateOfReturn;
    double V;
    financeLibrary::ComputeRateOfReturn(S, n, w, r, rateOfReturn, V);

    // Export data on the standard output
    financeLibrary::ExportData(std::cout, S, n, w, r, rateOfReturn, V);

    // Write data to a file
    std::string outputFileName = "./result.txt";
    std::ofstream file(outputFileName);

    if (!file.fail()) {
        financeLibrary::ExportData(file, S, n, w, r, rateOfReturn, V);
        std::cout << "Data exported to " << outputFileName << std::endl;
    } else {
        std::cerr << "Failed to open file: " << outputFileName << std::endl;
    }

    file.close();

    delete[] w;
    delete[] r;

    return 0;
}
