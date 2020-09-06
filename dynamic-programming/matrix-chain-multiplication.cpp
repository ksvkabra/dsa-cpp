#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int matrixChainRecursive(vector<int> arr, int i, int j) {
    if (i>= j) {
        return 0;
    }
    int min = INT_MAX;
    for (int k=i; k<=j-1; k++) {
        int tempResult = matrixChainRecursive(arr, i, k) + matrixChainRecursive(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        if (tempResult < min) {
            min = tempResult;
        }
    }
    return min;
}

int matrixChainMemoization(vector<int> arr, int i, int j, vector<vector<int>> &t) {
    if (i>= j) {
        return 0;
    }
    if (t[i][j] != -1) {
        return t[i][j];
    }
    int min = INT_MAX;
    for (int k=i; k<=j-1; k++) {
        int tempResult = matrixChainMemoization(arr, i, k, t) + matrixChainMemoization(arr, k+1, j, t) + arr[i-1]*arr[k]*arr[j];
        if (tempResult < min) {
            min = tempResult;
        }
    }
    return t[i][j]=min;
}


int main() {
    vector<int> arr{ 40, 20, 30, 10, 30 };
    vector<vector<int>> t(arr.size(), vector<int>(arr.size(), -1));
    cout<<matrixChainMemoization(arr, 1, arr.size()-1, t)<<endl;
    cout<<matrixChainRecursive(arr, 1, arr.size()-1)<<endl;
    return 0;
}