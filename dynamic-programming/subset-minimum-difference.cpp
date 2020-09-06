// divide the set in two subets, such that the difference between two subsets is minimum

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

vector<int> subSetSum(vector<int> arr, int range, int n) {
    vector<vector<int>> t(n+1, vector<int>(range+1, INT_MAX));
    vector<int> possibleSums(0);
    for (int j=0; j<range+1; j++) {
        t[0][j] = 0;
    }
    for (int i=0; i<n+1; i++) {
        t[i][0] = 1;
    }
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<range+1; j++) {
            if (arr[i-1] <= j) {
                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    // for (vector<int> i: t) {
    //     for (int j: i) {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i=0; i<(range+1)/2; i++) {
        if (t[n][i]) {
            possibleSums.push_back(i);
        }
    }
    // for (int i: possibleSums) {
    //     cout<<i<<", ";
    // }
    return possibleSums;
}

int minimumSubsetDifference(vector<int> arr, int range, int n) {
    vector<int> sums = subSetSum(arr, range, n);
    int minimumSum = INT_MAX;
    for (int i: sums) {
        minimumSum = min(minimumSum, range-2*i);
    }
    return minimumSum;
}

int numberSum(vector<int> arr) {
    int sum = 0;
    for (int i: arr) {
        sum += i;
    }
    return sum;
}

int main() {
    vector<int> arr{ 1, 4, 7 };
    int range = numberSum(arr);
    cout<<"minimum subset difference is- "<<minimumSubsetDifference(arr, range, 3)<<endl;
    return 0;
}