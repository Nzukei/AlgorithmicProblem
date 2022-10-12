#include <iostream>
#include <cmath>


void hanoi(int n, int from, int by, int to) {
    if (n == 1) {
        std::cout << from << to << "\n";
        return;
    }
    else {
        hanoi(n - 1, from, to, by);
        std::cout << from << to << "\n";
        hanoi(n - 1, by, from, to);
    }
}

int main() {
    int exponent;
    std::cin >> exponent;
    std::cout << pow(2, exponent) - 1 << "\n";
    
    hanoi(exponent, 1, 2, 3);
}
