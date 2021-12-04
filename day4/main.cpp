#include <bits/stdc++.h>

struct Piece {
    int value;
    bool marked;
};

struct Table {
    Piece pieces[5][5];
    int won_index = -1;
    int last_num = -1;
    void reset() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                pieces[i][j].value = -1;
                pieces[i][j].marked = false;
            }
        }
    }

    bool check_line() {
        int ok = false;
        for (int i = 0; i < 5; i++) {
            int l_ok = true;
            for (int j = 0; j < 5; j++) {
                if (pieces[i][j].marked == false) {
                    l_ok = false;
                    break;
                }
            }
            ok |= l_ok;
        }

        return ok;
    }

    bool check_column() {
        int ok = false;
        for (int j = 0; j < 5; j++) {
            int l_ok = true;
            for (int i = 0; i < 5; i++) {
                if (pieces[i][j].marked == false) {
                    l_ok = false;
                    break;
                }
            }
            ok |= l_ok;
        }

        return ok;
    }

    int64_t sum_unmarked() {
        int64_t sum = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (pieces[i][j].marked == false) {
                    sum += pieces[i][j].value;
                }
            }
        }

        return sum;
    }

    void print_table() {
         for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                std::cout << pieces[i][j].value << (pieces[i][j].marked ? "T" : "F") << " ";
            }
            std::cout << "\n";
        }
    }
};

int64_t solve(const std::vector<int> &numbers, std::vector<Table> tables) {
    int res = 0;
    for (auto num : numbers) {
        for (auto &table : tables) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (table.pieces[i][j].value == num) {
                        table.pieces[i][j].marked = true;
                    }
                }
            }

            if (table.check_line()) {
                return num * table.sum_unmarked();
            }

            if (table.check_column()) {
                return num * table.sum_unmarked();
            }
        }
    }

    return res;
}

int64_t solve2(const std::vector<int> &numbers, std::vector<Table> tables) {
    int res = 0;
    int index = 0;
    for (auto num : numbers) {
        if (index == tables.size()) {
            break;
        }
        for (auto &table : tables) {
            if (table.won_index != -1) {
                continue;
            }
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (table.pieces[i][j].value == num) {
                        table.pieces[i][j].marked = true;
                    }
                }
            }

            if (table.check_line() || table.check_column()) {
                table.won_index = index;
                table.last_num = num;
                index++;
            }
        }
    }

    for (auto &table : tables) {
        if (table.won_index == tables.size() - 1) {
            std::cout << table.last_num << "\n";
            return table.last_num * table.sum_unmarked();
        }
    }

    return res;
}

int main() {
    std::string line;
    std::vector<int> numbers;

    std::cin >> line;
    std::istringstream ss(line);
    std::string token;
    int counter = 0;
    Table t;
    std::vector<Table> tables;

    while (std::getline(ss, token, ',')) {
        numbers.push_back(std::stoi(token));
    }


    while (std::cin >> line) {
        t.pieces[counter / 5][counter % 5].value = std::stoi(line);
        t.pieces[counter / 5][counter % 5].marked = false;
        counter++;
        if (counter == 25) {
            tables.push_back(t);
            t.reset();
            counter = 0;
        }
    }

    std::cout << solve(numbers, tables) << "\n";
    std::cout << solve2(numbers, tables) << "\n";

    return 0;
}