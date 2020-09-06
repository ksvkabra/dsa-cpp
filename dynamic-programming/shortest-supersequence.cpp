#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int shortestCommonSupersequence(string s1, string s2, int m, int n) {
    vector<vector<int>> t(m+1, vector<int>(n+1, -1));

    for (int i=0; i<m+1; i++) {
        for (int j=0; j<n+1; j++) {
            if (i==0 || j ==0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i=1; i<m+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (s1[i-1]== s2[j-1]) {
                t[i][j] = 1+ t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }

    // backtracking supersequence
    int i =m, j=n;
    string result;
    while (i > 0 && j>0) {
        if (s1[i-1] == s2[j-1]) {
            result.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if (t[i][j-1] > t[i-1][j]) {
                result.push_back(s2[j-1]);
                j--;
            }
            else {
                result.push_back(s1[i-1]);
                i--;
            }
        }
    }
    if (i != 0) {
        string::iterator it = s1.begin();
        while (it != s1.begin()+i) {
            result += *it;
            it++;
        }
    }
    else if (j != 0) {
        cout<<"j"<<j<<endl;
        string::iterator it = s2.begin();
        while (it != s2.begin()+i) {
            result += *it;
            it++;
        }
    }
    reverse(result.begin(), result.end());
    cout<<result<<endl;
    return m+n-t[m][n];
}


int main() {
    string s1 = "abcdaf";
    string s2 = "acbcf";
    cout<<shortestCommonSupersequence(s1, s2, s1.length(), s2.length());
    return 0;
}