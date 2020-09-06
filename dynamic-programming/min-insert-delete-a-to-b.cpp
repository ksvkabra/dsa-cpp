#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int longestCommonSubsequence(string s1, string s2, int m, int n) {
    vector<vector<int>> t(m+1, vector<int>(n+1, -1));

    for (int i=0; i<m+1; i++) {
        for (int j=0; j<n+1; j++) {
            if (i ==0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i=1; i<m+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (s1[i-1] == s2[j-1]) {
                t[i][j] = 1+ t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }

    for (vector<int> i: t) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return t[m][n];
}

int main() {
    string s1 = "heap";
    string s2 = "pea";
    int n = s2.length();
    int m = s1.length();
    int lscLength = longestCommonSubsequence(s1, s2, m, n);
    cout<<"insertions- "<<n-lscLength<<endl;
    cout<<"deletions- "<<m-lscLength<<endl;
}