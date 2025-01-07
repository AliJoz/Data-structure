#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

// ساختار برای نگه داشتن نتایج
struct Result {
    int min_waste;
    int producer_index;
    vector<pair<int, int>> pack_box_pairs;
};

// تابعی برای خواندن ورودی از فایل
void read_input(int& N, vector<int>& packages, int& M, vector<vector<int>>& boxes) {
    ifstream infile("input.txt");
    
    infile >> N;
    packages.resize(N);
    for (int i = 0; i < N; i++) {
        infile >> packages[i];
    }
    infile >> M;
    boxes.resize(M);
    for (int i = 0; i < M; ++i) {
        int size;
        while (infile >> size) {
            boxes[i].push_back(size);
            if (infile.peek() == '\n') break;
        }
    }
    infile.close();
}

// تابع اصلی برای پیدا کردن نتیجه بهینه
Result find_optimal_solution(const vector<int>& packages, const vector<vector<int>>& boxes) {
    int N = packages.size();
    int M = boxes.size();
    Result best_result = { numeric_limits<int>::max(), -1, {} };

    for (int i = 0; i < M; ++i) {
        vector<int> box_sizes = boxes[i];
        sort(box_sizes.begin(), box_sizes.end());
        vector<pair<int, int>> current_solution;
        int total_waste = 0;
        bool valid = true;

        for (int pkg : packages) {
            auto it = lower_bound(box_sizes.begin(), box_sizes.end(), pkg);
            if (it == box_sizes.end()) {
                valid = false;
                break;
            }
            int box_size = *it;
            total_waste += box_size - pkg;
            current_solution.push_back({ pkg, box_size });
        }

        if (valid && total_waste < best_result.min_waste) {
            best_result = { total_waste, i + 1, current_solution };
        }
    }

    return best_result;
}

int main() {
    int N, M;
    vector<int> packages;
    vector<vector<int>> boxes;

    // خواندن ورودی از فایل
    read_input( N, packages, M, boxes);

    // پیدا کردن نتیجه بهینه
    Result result = find_optimal_solution(packages, boxes);

    // چاپ نتیجه
    if (result.producer_index == -1) {
        cout << "No valid solution found." << endl;
    }
    else {
        cout << result.min_waste << endl;
        cout << result.producer_index << endl;
        for (const auto& pair : result.pack_box_pairs) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    return 0;
}
