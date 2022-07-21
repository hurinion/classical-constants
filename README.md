# Computations of Pi

- [Introduction](#introduction)
- [Ramanujan-Sato series](#ramanujan-sato-series)
## Introduction

The purpose of this code is to computate to an arbitrary precision the value of $\pi$ using the GNU MP (GMP) library in C++.

## Ramanujan-Sato series

The [Ramanujan-Sato series](https://en.wikipedia.org/wiki/Ramanujan%E2%80%93Sato_series, "Wikipedia: Ramanujan–Sato series") is a precise formula. It is given as 
$$\frac{1}{\pi} = \frac{2 \sqrt{2}}{99^2} \sum_{k = 0}^{\infty} \frac{(4 k)^k}{k!^4} \frac{26390 k + 1103}{396^{4k}}.$$

Computer handling of a large number of digits is limited by its hardware and software. An software implementation of arbitrary arithmetic precision is used here.

Dependancies:

- GNP library; see [GMP manual](https://gmplib.org/manual/Introduction-to-GMP "Introduction to GNU MP"), [C++ interface](https://gmplib.org/manual/C_002b_002b-Class-Interface "C++ Class Interface")

For Debian installation:

```bash
sudo apt-get install libgmp3-dev
```

Compile and execute:
```bash
 g++ -o ramanujan_sato.exe ramanujan_sato.cpp -lgmpxx -lgmp
 ./ramanujan_sato.exe
```

Output:
```
3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328...
```

```C++
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
```





