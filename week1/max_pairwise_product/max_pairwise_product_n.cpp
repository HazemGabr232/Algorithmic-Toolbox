#include <iostream>
#include <vector>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    int first_max = -1;
    int second_max = -1;

    for (int i = 0; i < n; ++i) {
        if ((first_max==-1) || (numbers[i] > numbers[first_max])) {
            first_max = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if ( (i != first_max) && ((second_max == -1) || (numbers[i] > numbers[second_max]))) {
            second_max = i;
        }
    }

    return max_product= (long long )numbers[first_max] * numbers[second_max];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers); std::cout << "\n";
    return 0;
}
