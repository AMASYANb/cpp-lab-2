#include <iostream>
#include <chrono> 

double v_stepenb(double osnovanie_stepeni, int stepenb) {
    if (stepenb == 0) return 1; 
    if (stepenb == 1) return osnovanie_stepeni;

    double result = 1;
    for (int k = 0; k < stepenb; ++k) {
        result *= osnovanie_stepeni;
    }
    return result; 
}

double dvoinoi_factorial(int argument) {
    if (argument < 0) return 1; 
    double result = 1;
    for (int k = argument; k > 0; k -= 2) {
        result *= k;
    }
    return result; 
}

double T(double argument) {
    double sum1 = 0;
    double sum2 = 0;
    for (int k = 0; k <= 10; ++k) {
        sum1 += v_stepenb(argument, 2 * k + 1) / dvoinoi_factorial(2 * k + 1);
        sum2 += v_stepenb(argument, 2 * k) / dvoinoi_factorial(2 * k);
    }
    return sum1 / sum2; 
}

int main() {
    double y, chislitelb, znamenatelb, res;

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Enter your y:\n";
    std::cin >> y; 

    chislitelb = 7 * T(0.25) + 2 * T(1 + y);
    znamenatelb = 6 - T(v_stepenb(y, 2) - 1);
    res = chislitelb / znamenatelb;

    std::cout.precision(10);
    std::cout << "Ответ: " << res << std::endl; 

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start; 

    std::cout << "Время выполнения: " << duration.count() << " секунд" << std::endl;

    return 0; 
}