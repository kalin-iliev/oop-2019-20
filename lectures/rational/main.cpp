#include <iostream>
#include <cmath>
#include "rational.h"

unsigned fact(unsigned n) {
    unsigned product = 1;
    for(unsigned i = 2; i <= n; i++)
        product *= i;
    return product;
}

Rational ratexp(unsigned k, unsigned n) {
    Rational sum(0, 1);
    for(unsigned i = 0; i <= n; i++)
        // !!! sum += pow(k, i) / fact(i);
        // TODO: да се сметне общия член на редицата
        sum = add(sum, Rational(pow(k, i), fact(i)));
    return sum;
}

void testRationals() {
    // Rational r;
    Rational r(1, 2);
    Rational q = Rational(3, 4);
    q.printnl();
    r.printnl();
    q = r;
    q.printnl();
    std::cout << q.toDouble() << std::endl;
    q.read();
    q.printnl();
}

void testRatExp() {
    Rational r = ratexp(2, 14);
    r.printnl();
    std::cout << "r      = " << r.toDouble() << std::endl;
    std::cout << "exp(2) = " << exp(2) << std::endl;
}

int main(int, char**) {
    // testRationals();
    testRatExp();
}
