#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    static const long long MOD = 1000000007;
    static long long modMul(long long a, long long b) {
        return (a % MOD) * (b % MOD) % MOD;
    }


    
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,long long> freq;
        for(auto& p: points) freq[p[1]]++;
        long long sum = 0, sumSq = 0;
        for(auto& [y,cnt]: freq) {
            if(cnt >= 2) {
                long long b = cnt * (cnt - 1) / 2 % MOD;
                sum = (sum + b) % MOD;
                sumSq = (sumSq + b * b % MOD) % MOD;
            }
        }





        long long total = (modMul(sum, sum) - sumSq + MOD) % MOD;
        long long inv2 = (MOD + 1) / 2;
        return modMul(total, inv2);
    }
};
