#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<climits>
#include<iomanip>
#include<algorithm>

using namespace std;

int lcs(string s1, string s2, int m, int n) {
    if (m ==0 || n == 0) {
        return 0;
    }
    if (s1[m-1] == s2[n-1]) {
        return 1+lcs(s1, s2, m-1, n-1);
    }
    return max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
}

int lcsMemoization(string s1, string s2, int m, int n, vector<vector<int>> &t) {

    if (m == 0 || n == 0) {
        return 0;
    }
    if (t[m][n] != -1) {
        return t[m][n];
    }
    if (s1[m-1] == s2[n-1]) {
        return t[m][n] = 1+lcsMemoization(s1, s2, m-1, n-1, t);
    }
    return t[m][n] = max(lcsMemoization(s1, s2, m-1, n, t), lcsMemoization(s1, s2, m, n-1, t));
}

int lcsTopDown(string s1, string s2, int m, int n) {
    vector<vector<int>> t(m+1, vector<int>(n+1, -1));
    for (int i=0; i<m+1; i++) {
        t[i][0] = 0;
    }
    for (int i=0; i<n+1; i++) {
        t[0][i] = 0;
    }

    for (int i=1; i<m+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (s1[i-1] == s2[j-1]) {
                t[i][j] = 1+t[i-1][j-1];
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
    return t[m][n];
}
int main() {
    string s1 = "abcdgh";
    string s2 = "abedfhr";
    cout<<lcs(s1, s2, s1.length(), s2.length())<<endl;
    vector<vector<int>> t(s1.length()+1, vector<int>(s2.length()+1, -1));
    lcsMemoization(s1, s2, s1.length(), s2.length(), t);
    cout<<t[s1.length()][s2.length()];
    cout<<lcsTopDown(s1, s2, s1.length(), s2.length())<<endl;
    return 0;
}