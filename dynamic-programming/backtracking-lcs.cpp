#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string lcsBacktracking(string s1, string s2, int m, int n) {
    string result;
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
                t[i][j] = 1 + t[i-1][j-1];
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
    int i=m, j=n;
    while (i>0 && j>0) {
        if (s1[i-1] == s2[j-1]) {
            result.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if (t[i][j-1]>t[i-1][j]) {
                j--;
            }
            else {
                i--;
            }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // string s1 = "abcdgh";
    // string s2 = "aedfhr";
    string s1 = "axy";
    string s2 = "adxcpy";
    int m = s1.length();
    int n = s2.length();
    cout<<lcsBacktracking(s1, s2, m, n);
    return 0;
}