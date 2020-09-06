#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

int rodLengthMaxProfit(vector<int> lengths, vector<int> prices, int l, int n) {
    vector<vector<int>> T(n+1, vector<int>(l+1, INT_MAX));

    for (int i=0; i<n+1; i++) {
        T[i][0] = 0;
    }

    for (int i=0; i<l+1; i++) {
        T[0][i] = 0;
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<l+1; j++) {
            if (lengths[i-1] <=j) {
                T[i][j] = max(T[i-1][j], prices[i-1] + T[i][j-lengths[i-1]]);
            }
            else {
                T[i][j] = T[i-1][j];
            }
        }
    }

    for (vector<int> i: T) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return T[n][l];
}

int main() {
    vector<int> lengths{ 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<int> prices{ 1, 5, 8, 9, 10, 17, 17, 20 };
    int length = 8;

    cout<<rodLengthMaxProfit(lengths, prices, length, 8)<<endl;
    return 0;
}