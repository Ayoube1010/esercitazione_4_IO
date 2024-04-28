#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

using namespace std;

namespace financeLibrary{

bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r);

void ComputeRateOfReturn(const double& S,
                         const size_t& n,
                         const double* const& w,
                         const double* const& r,
                         double& rateOfReturn,
                         double& V);

void ExportData(ostream& out,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                const double& rateOfReturn,
                const double& V);

string ArrayToString(const size_t& n,
                          const double* const& v);
}
#endif // UTILS_HPP
