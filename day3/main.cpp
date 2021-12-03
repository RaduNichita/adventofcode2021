#include <bits/stdc++.h>

int64_t solve(const int num_bits, const std::vector<std::string> &v) {
    int n = v.size();
    int num1 = 0;
    int num2 = 0;
    for (int b = 0; b < num_bits; b++) {
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (v[i][b] == '1') {
                ones++;
            }
        }
        if (ones >= n / 2) {
            num1 = num1 * 2 + 1;
            num2 = num2 * 2;
        } else {
            num2 = num2 * 2 + 1;
            num1 = num1 * 2;
        }
    }
   
    return num1 * num2;
}

int64_t solve2(const int num_bits, const std::vector<std::string> &v) {
    auto oxygen = 0;
    auto carbon = 0;

    auto most_common = v;
    auto less_common = v;
    for (int b = 0; b < num_bits; b++) {
        int ones_common = 0;
        int ones_not_common = 0;

        std::vector<std::string> most_common_ones;
        std::vector<std::string> most_common_zeros;
        std::vector<std::string> less_common_ones;
        std::vector<std::string> less_common_zeros;

        for (int i = 0; i < most_common.size(); i++) {
            if (most_common[i][b] == '1') {
                ones_common++;
                most_common_ones.emplace_back(most_common[i]);
            } else {
                most_common_zeros.emplace_back(most_common[i]);
            }
        }
        
        if (most_common.size() > 1) {
            if (2 * ones_common >= most_common.size()) {
            most_common = most_common_ones;
            oxygen = oxygen * 2 + 1;
            } else {
                most_common = most_common_zeros;
                oxygen = oxygen * 2;
            }
        } else if (most_common.size() == 1) {
            for (int j = b; j < num_bits; j++) {
                if (most_common[0][j] == '1') {
                    oxygen = oxygen * 2 + 1;
                } else {
                    oxygen = oxygen * 2;
                }
                most_common.clear();
            }
        }
        

        most_common_ones.clear();
        most_common_zeros.clear();
        for (int i = 0; i < less_common.size(); i++) {
            if (less_common[i][b] == '1') {
                ones_not_common++;
                less_common_ones.emplace_back(less_common[i]);
            } else {
                less_common_zeros.emplace_back(less_common[i]);
            }
        }
        
        if (less_common.size() > 1) {
            if (2 * ones_not_common >= less_common.size()) {
                carbon = carbon * 2;
                less_common = less_common_zeros;
            } else {
                carbon = carbon * 2 + 1;
                less_common = less_common_ones;
            }
        } else if (less_common.size() == 1) {
            for (int j = b; j < num_bits; j++) {
                if (less_common[0][j] == '1') {
                    carbon = carbon * 2 + 1;
                } else {
                    carbon = carbon * 2;
                }
                less_common.clear();
            }
        }
       

        less_common_ones.clear();
        less_common_zeros.clear();
    }

    return oxygen * carbon;
}

int main() {
    std::string line;
    std::vector<std::string> numbers;
    size_t num_bits = 0;
    while (std::cin >> line) {
        numbers.emplace_back(line);
        num_bits = std::max(num_bits, line.size());
    }

    std::cout << solve(num_bits, numbers) << "\n";
    std::cout << solve2(num_bits, numbers) << "\n";
    return 0;
}