#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class Solution {
public:
    long long splitArray(vector<int>& data) {
        int len = data.size();
        if (len == 0) return 0;

        long long totalSum = 0;
        for (int val : data) {
            totalSum += val;
        }

        if (len <= 2) {
            return abs(totalSum);
        }

        vector<bool> prime(len, true);
        prime[0] = false;
        prime[1] = false;

        for (int p = 2; p * p < len; ++p) {
            if (prime[p]) {
                for (int k = p * p; k < len; k += p) {
                    prime[k] = false;
                }
            }
        }

        long long primeSum = 0;
        for (int i = 2; i < len; ++i) {
            if (prime[i]) {
                primeSum += data[i];
            }
        }

        return abs(2 * primeSum - totalSum);
    }
};
