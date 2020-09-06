#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int unboundedKnapsack(vector<int> weight, vector<int>value, int sum, int n) {
    vector<vector<int>> T(n+1, vector<int>(sum+1, INT_MAX));

    for (int i=0; i<n+1; i++) {
        T[i][0] = 0;
    }
    for (int i=0; i<sum+1; i++) {
        T[0][i] = 0;
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<sum+1; j++) {
            if (weight[i-1] <= j) {
                T[i][j] = max(T[i-1][j], value[i-1] + T[i][j-weight[i-1]]);
            }
            else {
                T[i][j]= T[i-1][j];
            }
        }
    }
    for (vector<int> i: T) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return T[n][sum];
}

int main() {
    vector<int> value{ 1, 3, 4, 5 };
    vector<int> weight{ 1, 4, 5, 7 };
    int sum = 7;
    cout<<unboundedKnapsack(weight, value, sum, 4);
    return 0;
}