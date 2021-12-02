#include <bits/stdc++.h>

auto solve(const std::vector<std::pair<std::string, int64_t>> &commands) {
    int64_t horizontal = 0;
    int64_t depth = 0;

    std::unordered_map<std::string, std::pair<int, int>> directions = {
        {"forward", {1, 0}},
        {"down", {0, 1}},
        {"up", {0, -1}},
    };

    for (auto &[direction, position] : commands) {
        auto &[dx, dy] = directions[direction];
        horizontal += dx * position;
        depth += dy * position;
    }

    return abs(horizontal * depth);
}

auto solve2(const std::vector<std::pair<std::string, int64_t>> &commands) {
    int64_t horizontal = 0;
    int64_t depth = 0;
    int64_t aim = 0;

    std::unordered_map<std::string, std::pair<int, int>> directions = {
        {"forward", {1, 0}},
        {"down", {0, 1}},
        {"up", {0, -1}},
    };

    for (auto &[direction, position] : commands) {
        auto &[dx, dy] = directions[direction];
        horizontal += dx * position;
        aim += dy * position;
        depth += aim * dx * position;

    }

    return abs(horizontal * depth);
}

int main() {

    std::string line;
    std::vector<std::pair<std::string, int64_t>> v;

    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string command;
        int64_t position;
        ss >> command >> position;
        v.emplace_back(command, position);
    }

    std::cout << solve(v) << "\n";
    std::cout << solve2(v) << "\n";
    return 0;
}