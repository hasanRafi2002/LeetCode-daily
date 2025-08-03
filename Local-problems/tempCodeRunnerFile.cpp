long long minCost(vector<int>& bascket1, vector<int>& bascket2){
    unordered_map<int , int> freq;
    int n = bascket1.size();

    for (int i = 0; i<n; ++i){
        freq[bascket1[i]]++;
        freq[bascket2[i]]--;
    }

    vector <int> excess;
    long long minVal = LLONG_MAX;

    for(auto& [fruit, count] : freq){
        if(count % 2 != 0){
            return -1;
        }

        for(int i = 0; i<abs(count)/2; ++i){
            excess.push_back(fruit);
        }
        minVal = min(minVal, (long long)fruit);
    }

    sort(excess.begin(), excess.end());
    long long res = 0;
    int m = excess.size()/2;

    for (int i = 0; i<m; ++i){
        res += min((long long)excess[i], 2*minVal);
    }
    return res;

}
