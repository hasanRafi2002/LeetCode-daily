#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascal(int numRows){
    vector<vector<int>> triangle;

    for(int i = 0; i<numRows; ++i){
        vector<int> row(i+1, 1);

        for(int j = 1; j<i; ++j){
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}

int main(){
    int numRows;
    cout<<"Enter number of rows: ";
    cin>>numRows;
    vector<vector<int>> result = generatePascal(numRows);

    cout<<"\npascal's triangle:\n";

    for (const auto& row : result){
        for(int num : row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}