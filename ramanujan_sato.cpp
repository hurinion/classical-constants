#include <iostream>
#include <cmath>
#include <iomanip>

#include <gmp.h>
#include <gmpxx.h>


using namespace std;

/. computes an iteration of pi ./

mpf_class ramanujan_sato(int iterations) {

    mpf_class A = 26390, B = 1103, C = 24591257856, C_ = 1, num, den, sum;

    for (mpz_class k = 0; k < iterations; k++, C_ *= C) {

        num = factorial(4*k)*(A*k + B);
        den = (factorial(k)*factorial(k)*factorial(k)*factorial(k))*C_;

        sum += num/den;
    }

    mpf_class D = 9801, E = 2*sqrt((mpf_class)2), out;

    out = D/E;
    out /= sum;

    return out;

}

void calcpi() {
    
    /. each iteration computes 8 digits of pi ./
        
    int iterations = 100, decimals = iterations * 8, precision = decimals * log2(10);

    mpf_set_default_prec(precision);

    mpf_class sum = ramanujan_sato(iterations);

    cout << setprecision(decimals) << sum << endl;

}

int main() {

    clock_t t0, t1;

    t0 = clock();

    calcpi();

    t1 = clock();
    cout << "Time elapsed: "
         << (double)(t1 - t0) / CLOCKS_PER_SEC
         << " seconds." << endl;
    
    return 0;

}

