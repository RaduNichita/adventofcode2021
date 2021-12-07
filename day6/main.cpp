#include <bits/stdc++.h>

int64_t solve(const std::vector<int> &fishes, const int num_days) {
    int64_t res = 0;
    int64_t count[9] = {};

    for (auto &fish : fishes) {
        count[fish]++;
    }

    for (int i = 0; i < num_days; i++) {
        int64_t tmp = count[0];
        for (int j = 0; j < 8; j++) {
            count[j] = count[j + 1];
        }
        count[8] = tmp;
        count[6] += tmp;
    }

    for (int i = 0; i < 9; i++) {
        res += count[i];
    }

    return res;

}

int main() {

    int x;
    std::vector<int> v;
    std::string line;
    std::string s_int;
    std::cin >> line;
    std::stringstream ss(line);
    while (std::getline(ss, s_int, ',')) {
        auto x = std::stoi(s_int);
        v.push_back(x);
    }

    std::cout << solve(v, 80) << "\n";
    std::cout << solve(v, 256) << "\n";
    return 0;
}