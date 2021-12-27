#include <bits/stdc++.h>

int64_t solve(const std::vector<std::string> &lines)
{
    int64_t res = 0;
    std::unordered_set<int> exact_lengths = {4, 2, 3, 7};
    for (auto &line : lines)
    {
        std::stringstream ss(line);
        std::string token;
        std::unordered_set<std::string> signals;
        for (int i = 0; i < 10; i++)
        {
            ss >> token;
            std::sort(token.begin(), token.end());
            signals.insert(token);
        }
        ss >> token;

        while (ss >> token)
        {
            std::sort(token.begin(), token.end());
            if (signals.find(token) != signals.end() && exact_lengths.find(token.size()) != exact_lengths.end())
            {
                res += 1;
            }
        }
    }
    return res;
}

char find_upper(const std::string &one, const std::string &seven)
{
    int i = 0, j = 0;
    while (i < one.size() && j < seven.size())
    {
        if (one[i] != seven[j])
        {
            return seven[j];
        }
        i++;
        j++;
    }
    return seven[j];
}

char find_upper_right(const std::string &one, const std::vector<std::string> &length_six)
{
    std::unordered_set<char> characters;
    for (auto &c : one)
    {
        characters.insert(c);
    }

    for (auto &segment : length_six)
    {
        int ok = 0;
        for (auto &signal : segment)
        {
            if (characters.find(signal) != characters.end())
            {
                ok++;
            }
        }

        if (ok != characters.size())
        {
            for (auto &signal : segment)
            {
                if (characters.find(signal) != characters.end())
                {
                    characters.erase(signal);
                }
            }
            assert(characters.size() == 1);
            return *(characters.begin());
        }
    }

    return -1;
}

char find_bottom_right(const std::string &one, const char upper_right)
{
    for (auto &c : one)
    {
        if (c != upper_right)
        {
            return c;
        }
    }
    return -1;
}

char find_bottom(const std::vector<std::string> &length_five, const std::string &four, const char upper)
{
    std::unordered_map<char, int> freq;
    for (int i = 0; i < 5; i++)
    {
        freq[length_five[0][i]]++;
        freq[length_five[1][i]]++;
        freq[length_five[2][i]]++;
    }

    for (auto &[k, v] : freq)
    {
        if (v == 3 && four.find(k) == std::string::npos && k != upper)
        {
            return k;
        }
    }
    return -1;
}

char find_middle(const std::vector<std::string> &length_five, const char upper, const char bottom)
{
    std::unordered_map<char, int> freq;
    for (int i = 0; i < 5; i++)
    {
        freq[length_five[0][i]]++;
        freq[length_five[1][i]]++;
        freq[length_five[2][i]]++;
    }

    for (auto &[k, v] : freq)
    {
        if (v == 3 && k != upper && k != bottom)
        {
            return k;
        }
    }
    return -1;
}

char find_upper_left(const std::string &four, const char upper_right, const char middle, const char bottom_right)
{
    for (auto &c : four)
    {
        if (c != upper_right && c != bottom_right && c != middle)
        {
            return c;
        }
    }

    return -1;
}

char find_bottom_left(const std::string &eight, const std::vector<char> other_signals)
{
    std::unordered_set<char> all_signals({eight.begin(), eight.end()});
    for (auto &signal : other_signals)
    {
        all_signals.erase(signal);
    }

    assert(all_signals.size() == 1);
    return *(all_signals.begin());
}

bool is_anagram(std::string s1, std::string s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return (s1 == s2);
}

int64_t solve2(const std::vector<std::string> &lines)
{
    int64_t res = 0;
    std::string one;
    std::string four;
    std::string seven;
    std::string eight;

    std::vector<std::string> length_five;
    std::vector<std::string> length_six;

    char upper;
    char upper_left;
    char upper_right;
    char bottom_left;
    char bottom_right;
    char middle;
    char bottom;

    for (auto &line : lines)
    {
        std::stringstream ss(line);
        std::string token;
        std::unordered_map<std::string, int> signals;
        for (int i = 0; i < 10; i++)
        {
            ss >> token;
            std::sort(token.begin(), token.end());
            if (token.size() == 2)
            {
                one = token;
            }
            else if (token.size() == 3)
            {
                seven = token;
            }
            else if (token.size() == 4)
            {
                four = token;
            }
            else if (token.size() == 5)
            {
                length_five.push_back(token);
            }
            else if (token.size() == 6)
            {
                length_six.push_back(token);
            }
            else if (token.size() == 7)
            {
                eight = token;
            }
        }

        ss >> token;
        assert(length_five.size() == 3);
        assert(length_six.size() == 3);

        upper = find_upper(one, seven);
        upper_right = find_upper_right(one, length_six);
        bottom_right = find_bottom_right(one, upper_right);
        bottom = find_bottom(length_five, four, upper);
        middle = find_middle(length_five, upper, bottom);
        upper_left = find_upper_left(four, upper_right, middle, bottom_right);
        bottom_left = find_bottom_left(eight, {upper, upper_right, bottom_right, bottom, middle, upper_left});

        signals.insert({{upper, upper_left, upper_right, bottom_left, bottom_right, bottom}, 0});
        signals.insert({{upper_right, bottom_right}, 1});
        signals.insert({{upper, upper_right, middle, bottom_left, bottom}, 2});
        signals.insert({{upper, upper_right, middle, bottom_right, bottom}, 3});
        signals.insert({{upper_left, upper_right, middle, bottom_right}, 4});
        signals.insert({{upper, upper_left, middle, bottom_right, bottom}, 5});
        signals.insert({{upper, upper_left, middle, bottom_left, bottom_right, bottom}, 6});
        signals.insert({{upper, upper_right, bottom_right}, 7});
        signals.insert({{upper, upper_left, upper_right, middle, bottom_left, bottom_right, bottom}, 8});
        signals.insert({{upper, upper_left, upper_right, middle, bottom_right, bottom}, 9});

        int n = 0;
        while (ss >> token)
        {
            for (auto &[k, v] : signals)
            {
                if (is_anagram(k, token))
                {
                    n = n * 10 + v;
                    break;
                }
            }
        }

        res += n;

        length_five.clear();
        length_six.clear();
    }
    return res;
}

int main()
{
    std::string line;
    std::string values;
    std::vector<std::string> segments;
    while (std::getline(std::cin, line))
    {
        segments.push_back(line);
    }

    std::cout << solve(segments) << "\n";
    std::cout << solve2(segments) << "\n";
    return 0;
}