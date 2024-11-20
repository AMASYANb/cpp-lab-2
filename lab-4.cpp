#include <iostream>

int main() {
    unsigned n;

    std::cout << "Введите количество чашек: ";
    std::cin >> n;

    unsigned total_sum = n * (n + 1) / 2;

    if (total_sum % 2 != 0) {
        std::cout << "No" << std::endl;
        return 0;
    }

    std::cout << "Yes" << std::endl;

    const unsigned half_sum = total_sum / 2;
    unsigned half = half_sum;
    unsigned l = 0;

    std::cout << "Количество чашек Пети: ";
    for (unsigned i = n; i > 0; i--) {
        if (i <= half) {
            l++;
            half -= i;
        }
    }
    std::cout << l << std::endl;

    half = half_sum;
    std::cout << "Чашки первой кучи: ";
    for (unsigned i = n; i > 0; i--) {
        if (i <= half) {
            std::cout << i << " ";
            half -= i;
        }
    }
    std::cout << std::endl;

    unsigned M = n - l;
    std::cout << "Количество чашек Маши: " << M << std::endl;

    std::cout << "Чашки Маши: ";
    half = half_sum;
    for (unsigned i = n; i > 0; i--) {
        if (i > half) {
            std::cout << i << " ";
        } else {
            half -= i;
        }
    }
    std::cout << std::endl;

    return 0;
}