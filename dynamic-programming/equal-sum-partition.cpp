//given a set, find if it can be divided in two sets

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int sum(vector<int> arr) {
    int sumValue = 0;
    for (int i: arr) {
        sumValue+= i;
    }
    return sumValue;
}

bool checkIfPartitionExists(int sum) {
    return !(sum%2);
}

int subSetSum(vector<int> arr, int sum, int n) {
    vector<vector<int>> t(n+1, vector<int>(sum+1, INT_MAX));

    for (int j=0; j<sum+1; j++) {
        t[0][j] = 0;
    }
    for (int i=0; i<n+1; i++) {
        t[i][0] = 1;
    }
    for (int i=1; i< n+1; i++) {
        for (int j=1; j<sum+1; j++) {
            if (arr[i-1] <= j) {
                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    for (vector<int> i: t) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return t[n][sum];
}

int main() {
    vector<int> arr{ 1, 5, 5, 11 };
    int totalSum = sum(arr);
    cout<<totalSum<<endl;
    bool isPartition = checkIfPartitionExists(totalSum);
    if (isPartition) {
        cout<<subSetSum(arr, totalSum/2, 4)<<endl;
    }
    return 0;
}