#include <bits/stdc++.h>

int64_t solve(const std::vector<std::string> &lines) {
    int64_t res = 0;

    std::map<char, std::pair<char, int>> points = {
        {')', {'(', 3}},
        {']', {'[', 57}},
        {'}', {'{', 1197}},
        {'>', {'<', 25137}},
    };

    for (auto &line : lines) {
        std::stack<char> s;
        for (auto ch : line) {
            if ((ch == '(') || (ch == '[') || (ch == '{') || (ch == '<')) {
                s.push(ch);
            } else {
                auto to_match = points[ch];
                if (s.top() == to_match.first) {
                    s.pop();
                } else {
                    res += to_match.second;
                    break;
                }
            }
        }
    }

    return res;
}

int64_t solve2(const std::vector<std::string> &lines) {
    int64_t res = 0;
    std::vector<int64_t> all_costs;

    std::map<char, std::pair<char, int>> points = {
        {')', {'(', 1}},
        {']', {'[', 2}},
        {'}', {'{', 3}},
        {'>', {'<', 4}},
    };

    for (auto &line : lines) {
        std::stack<char> s;
        bool is_valid = true;
        for (auto ch : line) {
            if ((ch == '(') || (ch == '[') || (ch == '{') || (ch == '<')) {
                s.push(ch);
            } else {
                auto to_match = points[ch];
                if (s.top() == to_match.first) {
                    s.pop();
                } else {
                    is_valid = false;
                }
            }
        }

        if (is_valid) {
            int64_t cost = 0;
            while (!s.empty()) {
                auto to_match = s.top();
                for (auto &[k, v] : points) {
                    if (to_match == v.first) {
                        cost = cost * 5;
                        cost += v.second;
                        break;
                    }
                }
                s.pop();
            }
            all_costs.push_back(cost);
        }
    }

    std::sort(all_costs.begin(), all_costs.end());
    res = all_costs[all_costs.size() / 2];

    return res;
}

int main() {
    std::string line;
    std::vector<std::string> matrix;
    while (std::getline(std::cin, line)) {
        matrix.push_back(line);
    }

    std::cout << solve(matrix) << "\n";
    std::cout << solve2(matrix) << "\n";
    return 0;
}