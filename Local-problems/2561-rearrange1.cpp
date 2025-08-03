#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

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


int main(){
    int n;
    cout<<"Enter number of fruits in each basket: \n";
    cin>>n;
    vector<int> basket1(n), basket2(n);
    cout<<"Enter fruits in basket1: \n";

    for(int i =0; i<n; ++i){
        cin>>basket1[i];
    }

    cout<<"Enter fruits in basket2:\n";
    for(int i =0; i<n; ++i){
        cin>>basket2[i];
    }

    long long result = minCost(basket1, basket2);
    if(result == -1){
        cout<<"Impossible to make baskets equal\n";
    }else{
        cout<<"Minimum cost to rearrange : "<<result<<endl;
    }

    return 0;
}