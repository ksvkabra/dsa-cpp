#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int knapSackRecursive(vector<int> weight, vector<int> value, int W, int n) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (weight[n-1]>W) {
        return knapSackRecursive(weight, value, W, n-1);
    }
    return max(value[n-1] + knapSackRecursive(weight, value, W-weight[n-1], n-1), knapSackRecursive(weight, value, W, n-1));
}

int knapSackMemoization(vector<int> weight, vector<int> value, int W, int n, vector<vector<int>> &t) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (weight[n-1] <= W) {
        return t[n][W] = max(value[n-1] + knapSackMemoization(weight, value, W-weight[n-1], n-1, t), knapSackMemoization(weight, value, W, n-1, t));
    }
    else {
        return t[n][W] = knapSackMemoization(weight, value, W, n-1, t);
    }
    for (vector<int> i: t) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int knapSackTopDown(vector<int> weight, vector<int> value, int W, int n, vector<vector<int>> &p) {
    for (int i=0; i< W+1; i++) {
        p[0][i] = 0;
    }
    for (int j=0; j< n+1; j++) {
        p[j][0] = 0;
    }
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<W+1; j++) {
            if (weight[i-1] <= j) {
                p[i][j] = max(value[i-1]+p[i-1][j-weight[i-1]], p[i-1][j]);
            }
            else {
                p[i][j] = p[i-1][j];
            }
        }
    }
    for (vector<int> i: p) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return p[n][W];
}

int main() {
    vector<int> value{ 1, 3, 4, 5 };
    vector<int> weight{ 1, 4, 5, 7 };
    int W = 7;
    vector<vector<int>> t(4+1, vector<int>(W+1, INT_MAX));
    cout<<knapSackRecursive(weight, value, W, 4)<<endl;
    cout<<knapSackMemoization(weight, value, W, 4, t)<<endl;
    vector<vector<int>> p(4+1, vector<int>(W+1, INT_MAX));
    cout<<knapSackTopDown(weight, value, W, 4, p)<<endl;
    return 0;
}