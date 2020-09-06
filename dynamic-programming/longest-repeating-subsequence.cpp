#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int longestRepeatingSubsequence(string s1, int n) {
    vector<vector<int>> t(n+1, vector<int>(n+1, -1));
    string s2 = s1;
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<n+1; j++) {
            if (i == 0 || j == 0) {
                t[i][j] =0;
            }
        }
    }

    for (int i=1; i< n+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (i != j && s1[i-1] == s2[j-1]) {
                t[i][j] = 1+ t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    for (vector<int> i: t) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return t[n][n];
}

int main() {
    string s = "AABEBCDD";
    cout<<longestRepeatingSubsequence(s, s.length())<<endl;
    return 0;
}