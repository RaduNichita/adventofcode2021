#include <bits/stdc++.h>

struct Point {
    int x;
    int y;
};

struct Line {
    Point first;
    Point last;
};

Line parse_input(const std::string &line) {
    Line l;
    sscanf(line.c_str(), "%d,%d -> %d,%d", &l.first.x, &l.first.y, &l.last.x, &l.last.y);
    return l;
}

int64_t solve(const std::vector<Line> &lines) {
    int v[1000][1000];
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            v[i][j] = 0;
        }
    }

    for (auto &line : lines) {
        if (line.first.x == line.last.x) {
            int l_min = std::min(line.first.y, line.last.y);
            int l_max = std::max(line.first.y, line.last.y);
            for (int i = l_min; i <= l_max; i++) {
                v[line.first.x][i] += 1;
            }
        } else if (line.first.y == line.last.y) {
            int l_min = std::min(line.first.x, line.last.x);
            int l_max = std::max(line.first.x, line.last.x);
            for (int i = l_min; i <= l_max; i++) {
                v[i][line.first.y] += 1;
            }
        }
    }

    int64_t count = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (v[i][j] >= 2) {
                count += 1;
            }
        }
    }

    return count;
}

int64_t solve2(const std::vector<Line> &lines) {
    int v[1000][1000];
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            v[i][j] = 0;
        }
    }

    for (auto &line : lines) {
        if (line.first.x == line.last.x) {
            int l_min = std::min(line.first.y, line.last.y);
            int l_max = std::max(line.first.y, line.last.y);
            for (int i = l_min; i <= l_max; i++) {
                v[line.first.x][i] += 1;
            }
        } else if (line.first.y == line.last.y) {
            int l_min = std::min(line.first.x, line.last.x);
            int l_max = std::max(line.first.x, line.last.x);
            for (int i = l_min; i <= l_max; i++) {
                v[i][line.first.y] += 1;
            }
        } else if (line.first.y - line.first.x == line.last.y - line.last.x) {
            int l_min = std::min(line.first.x, line.last.x);
            int l_max = std::max(line.first.x, line.last.x);
            int diff = line.first.y - line.first.x;
            for (int i = l_min; i <= l_max; i++) {
                v[i][i + diff] += 1;
            }
        } else if (line.first.y + line.first.x == line.last.y + line.last.x) {
            int l_min = std::min(line.first.x, line.last.x);
            int l_max = std::max(line.first.x, line.last.x);
            int sum = abs(line.first.y + line.first.x);
            for (int i = 0; l_min + i <= l_max; i++) {
                v[l_min + i][sum - l_min - i] += 1;
            }
        }
    }

    int64_t count = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (v[i][j] >= 2) {
                count += 1;
            }
        }
    }

    return count;
}



int main() {
    std::string line;
    std::vector<Line> lines;
    while (std::getline(std::cin, line)) {
        lines.push_back(parse_input(line));
    }

    std::cout << solve(lines) << "\n";
    std::cout << solve2(lines) << "\n";
    return 0;
}
