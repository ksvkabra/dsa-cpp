#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<string>
#include<cstring>
using namespace std;

static int t[1001][1001];

bool isPalindrome(string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    bool isTrue= s == s2;
    return isTrue;
}

int palindromePartitionCost(string s1, int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (isPalindrome(s1.substr(i, j-i+1))) {
        return 0;
    }
    int minValue = INT_MAX;
    for (int k=i; k<j; k++) {
        int temp = 1+palindromePartitionCost(s1, i, k) + palindromePartitionCost(s1, k+1, j);
        minValue = min(minValue, temp);
    }
    return minValue;
}

int palindromePartitionCostMemoization(string s1, int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (isPalindrome(s1.substr(i, j-i+1))) {
        return 0;
    }
    int minValue = INT_MAX;
    int left = 0;
    int right = 0;
    for (int k=i; k<=j-1; k++) {
        if (t[i][k]  != -1) {
            left = t[i][k];
        }
        else {
            left = palindromePartitionCostMemoization(s1, i, k);
            t[i][k] = left;
        }
        if (t[k+1][j] != -1) {
            right = t[k+1][j];
        }
        else {
            right = palindromePartitionCostMemoization(s1, k+1, j);
            t[k+1][j] = right;
        }
        int temp = 1+right+left;
        minValue = min(minValue, temp);
    }
    return t[i][j] = minValue;
}

int main() {
    string s1 = "ababbbabbababa";
    memset(t, -1, sizeof(t));
    // cout<<palindromePartitionCost(s1, 0, s1.length()-1)<<endl;
    cout<<palindromePartitionCostMemoization(s1, 0, s1.length()-1)<<endl;

    return 0;
}