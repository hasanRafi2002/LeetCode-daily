#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k){
    int n = fruits.size();
    vector<int> pos, amt;

    for(auto& f : fruits){
        pos.push_back(f[0]);
        amt.push_back(f[1]);
    }

    int maxFruits = 0, left = 0, currSum = 0;

    for(int right = 0; right< n; ++right){
        currSum += amt[right];

        while(left <= right){
            int L = pos[left], R = pos[right];
            
            int dist = min(
                abs(startPos - L) + (R-L),
                abs(startPos - R) + (R-L)
            );

            if(dist <= k){
                break;
            }

            currSum -= amt[left++];
        }

        maxFruits = max(maxFruits, currSum);
    }
    return maxFruits;
}


int main(){
    int n;
    cout<<"Enter number of fruit baskets: ";
    cin>>n;

    vector<vector<int>> fruits(n, vector<int> (2));
    cout<<"Enter fruits positions and amounts (position amount):"<<endl;

    for(int i = 0; i<n; ++i){
        cin>> fruits[i][0]>> fruits[i][1];
    }

    int startPos, k;
    cout<<"Enter starting position: ";
    cin>>startPos;
    cout<<"Enter maximum steps (k): ";
    cin>>k;

    int result = maxTotalFruits(fruits, startPos, k);
    cout<<"Maximum fruits that can be collected: "<< result<<endl;

    return 0;
}