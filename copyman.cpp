#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumLength(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> f(k, vector<int>(k, 0)); 
    int ans = 0;

    for (int num : nums) {
        int x = num % k;
        for (int j = 0; j < k; ++j) {
            int y = (j - x + k) % k;
            f[x][y] = f[y][x] + 1;
            ans = max(ans, f[x][y]);
        }
    }

    return ans;
}

int main() {

    vector<int> nums = {1, 4, 1, 4};
    int k = 3;


    int result = maximumLength(nums, k);
    cout << "Maximum Length of Valid Subsequence: " << result << endl;

    return 0;
}
