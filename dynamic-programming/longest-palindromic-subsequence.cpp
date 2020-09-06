#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string longestPalindromicSubsequence(string s1, int n) {
    string s2 = s1;
    reverse(s1.begin(), s1.end());

    vector<vector<int>> t(n+1, vector<int>(n+1, -1));


    for (int i=0; i<n+1; i++) {
        for (int j=0; j<n+1; j++) {
            if (i ==0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (s1[i-1] == s2[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    // backtracking
    string result;
    int i=n, j=n;
    while (i >0 && j> 0) {
        if (s1[i-1] == s2[j-1]) {
            result.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if (t[i][j-1] > t[i-1][j]) {
                j--;
            }
            else {
                i--;
            }
        }
    }
    return result;
}

int numberOfDeletionsToMakeAStringPalindromic(string s1, int n) {
    return n - longestPalindromicSubsequence(s1, n).length();
}

int main() {
    string s = "agbcba";
    int n = s.length();
    cout<<longestPalindromicSubsequence(s, n)<<endl;
    cout<<"deletions required to change string to palindrome - "<<numberOfDeletionsToMakeAStringPalindromic(s, n);
    return 0;
}