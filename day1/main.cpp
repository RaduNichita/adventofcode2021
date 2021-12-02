#include <bits/stdc++.h>

auto solve(const std::vector<int64_t> &v) {
    const int n = v.size();
    auto increments = 0;

    for (int i = 1; i < n; i++) {
        if (v[i] > v[i - 1]) {
            increments++;
        }
    }

    return increments;
}

auto solve2(const std::vector<int64_t> &v) {
    const int n = v.size();
    auto increments = 0;
    for (int i = 3; i < n; i++) {
        if (v[i] > v[i - 3]) {
            increments++;
        }
    }

    return increments;
}

int main(void) {

    std::vector<int64_t> v;
    int64_t x;
    while (std::cin >> x) {
        v.emplace_back(x);
    }

    std::cout << solve(v) << "\n";
    std::cout << solve2(v) << "\n";

    return 0;
}