#include <bits/stdc++.h>

int64_t solve(const std::vector<std::string> matrix) {
    int res = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::pair<int, int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto node = matrix[i][j];
            int heigher = 0;
            int no_neights = 0;
            for (auto &[dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    auto neigh = matrix[x][y];
                    if (neigh > node) {
                        heigher++;
                    }
                    no_neights++;
                }
            }

            if (heigher == no_neights) {
                res = res + (node - '0') + 1;
            }
        }
    }

    return res;
}

int64_t solve2(const std::vector<std::string> matrix) {
    int res = 1;
    int n = matrix.size();
    int m = matrix[0].size();
    std::queue<std::pair<int, int>> q;
    std::vector<int> basins_sizes;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    std::vector<std::pair<int, int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto node = matrix[i][j];
            int heigher = 0;
            int no_neights = 0;
            for (auto &[dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    auto neigh = matrix[x][y];
                    if (neigh > node) {
                        heigher++;
                    }
                    no_neights++;
                }
            }

            if (heigher == no_neights) {
                q.push({i, j});
                visited[i][j] = true;
                int basin_size = 1;
                while (!q.empty()) {
                    auto [node_x, node_y] = q.front();
                    q.pop();
                    for (auto &[dx, dy] : directions) {
                        int x = node_x + dx;
                        int y = node_y + dy;
                        if (x >= 0 && x < n && y >= 0 && y < m && (!visited[x][y]) && (matrix[x][y] - '0') != 9) {
                            q.push({x, y});
                            visited[x][y] = true;
                            basin_size++;
                        }
                    }
                }
                basins_sizes.push_back(basin_size);
            }
        }
    }

    std::sort(basins_sizes.begin(), basins_sizes.end(), std::greater<int>());
    res = basins_sizes[0] * basins_sizes[1] * basins_sizes[2];

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