// count number of subsets with given difference
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int subsetCount(vector<int> arr, int sum, int n) {
    vector<vector<int>> t(n+1, vector<int>(sum+1, INT_MAX));

    for (int i=0; i<sum+1; i++) {
        t[0][i] = 0;
    }

    for (int i=0; i<n+1; i++) {
        t[i][0] = 1;
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<sum+1; j++) {
            if (arr[i-1] <= j) {
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
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

int numberSum(vector<int> arr) {
    int sum = 0;
    for (int i: arr) {
        sum += i;
    }
    return sum;
}

int differenceCountSubset(vector<int> arr, int difference, int n) {
    int sum = (difference+ numberSum(arr))/2;
    return subsetCount(arr, sum, n);
}


int main() {
    vector<int> arr{ 1, 1, 2, 3 };
    int difference = 1;
    cout<<differenceCountSubset(arr, difference, 4)<<endl;
    return 0;
}