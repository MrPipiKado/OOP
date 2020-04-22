#include <iostream>
#include "Set.h"
#include "complex.h"
using namespace SET;
int main()
{
    /*int tmp[6] = {1, 2,2, 3, 4, 5};
    int tmp2[6] = { 4, 5, 6, 6, 7, 8};
    Set<int> A(tmp, 6);
    Set<int> B(tmp2, 6);
    Set<int> C;*/
    Complex tmp[6]={Complex(1, 1), Complex(2, 2),
                    Complex(2, 2), Complex(3, 3),
                    Complex(4, 4), Complex(5, 5),};
    Complex tmp2[6]={Complex(4, 4), Complex(5, 5),
                     Complex(5, 5), Complex(6, 6),
                     Complex(7, 7), Complex(8, 8),};
    Set<Complex> A(tmp, 6);
    Set<Complex> B(tmp2, 6);
    Set<Complex> C;
    std::cout << A << std::endl;
    C = A+B;
    std::cout << C << std::endl;
    C = A-B;
    std::cout << C << std::endl;
    C = A^B;
    std::cout << C << std::endl;
    C = A+Complex(10, 10);
    std::cout << C << std::endl;
    C = A-Complex(4, 4);
    std::cout << C << std::endl;
    return 0;
}
