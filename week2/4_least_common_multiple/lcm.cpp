#include <iostream>


int gcd_fast(int a, int b) {
    /* this function calculates a%b and it stops only when this remainder equals 0
     * the gcd(a) equals the gcd(b, a%b)
     * here we return the left term which is the greatest common divisor */
    if (b == 0)
        return a;

    return gcd_fast(b, a % b);
}


long long lcm_fast(int a, int b) {
    /* key idea comes from the equation a x b = LCM(a, b) * GCD (a, b)*/

    return (((long long)a * b) / gcd_fast(a, b));
}


long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long)a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long)a * b;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}

