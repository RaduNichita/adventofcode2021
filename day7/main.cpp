#include <bits/stdc++.h>


constexpr int64_t sum(const int n) {
    return n * (n + 1) / 2;
}

int64_t solve(const std::vector<int> &v, int max_elem) {
    int64_t min_fuel = INT_MAX;
    int n = v.size();

    for (int i = 0; i < max_elem; i++) {
        int64_t sum = 0;
        for (int j = 0; j < n; j++) {
            sum += abs(v[j] - i);
        }
        
        min_fuel = std::min(min_fuel, sum);
    }

    return min_fuel;
}

int64_t solve2(const std::vector<int> &v, const int max_elem) {
    int64_t min_fuel = INT_MAX;
    int n = v.size();

    for (int i = 0; i < max_elem; i++) {
        int64_t s = 0;
        for (int j = 0; j < n; j++) {
            s += sum(abs(v[j] - i));
        }
        
        min_fuel = std::min(min_fuel, s);
    }

    return min_fuel;
}

int main() {

    int x;
    int max_elem = INT_MIN;
    std::vector<int> v;
    std::string line;
    std::string s_int;
    std::cin >> line;
    std::stringstream ss(line);
    while (std::getline(ss, s_int, ',')) {
        auto x = std::stoi(s_int);
        v.push_back(x);
        if (max_elem < x) {
            max_elem = x;
        }
    }

    std::cout << solve(v, max_elem) << "\n";
    std::cout << solve2(v, max_elem) << "\n";
    return 0;
}

