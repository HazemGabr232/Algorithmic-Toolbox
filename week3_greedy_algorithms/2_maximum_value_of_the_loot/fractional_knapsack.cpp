#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max_element;

double get_optimal_value(double capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int current_max;

    vector<double> v_per_w(weights.size());

    for (int i = 0; i < weights.size(); i++)
        v_per_w[i] = values[i] / (double)weights[i];

    for (int i = 0; i < weights.size(); i++) {

        current_max = std::distance(v_per_w.begin(), max_element(v_per_w.begin(), v_per_w.end()));
        if (weights[current_max] <= capacity) {
            value += values[current_max];
            capacity -= weights[current_max];
            v_per_w[current_max] = 0;
        }
        else if (weights[current_max] > capacity && capacity != 0) {
            value += values[current_max] * ((double)capacity / (double)weights[current_max]);
            v_per_w[current_max] = 0;
            capacity = 0;
        }
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
