#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int> & fruits){
    unordered_map<int, int> basket;
    int left = 0, maxFruits = 0;


    for(int right = 0; right<fruits.size(); ++right){
        basket[fruits[right]]++;

        while(basket.size()>2){
            basket[fruits[left]]--;
            if(basket[fruits[left]] == 0){
                basket.erase(fruits[left]);
            }
            left++;
        }
        maxFruits = max(maxFruits, right - left + 1);

    }
    return maxFruits;
}

int main(){
    int n;
    cout<<"Enter number of fruits: ";
    cin>> n;

    vector<int> fruits(n);
    cout<<"Enter fruit types: ";

    for(int i =0; i<n; i++){
        cin>>fruits[i];
    }

    int result = totalFruit(fruits);
    cout<<"Maximum fruits you can collect: "<< result<<endl;

    return 0;
}