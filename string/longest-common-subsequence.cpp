#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int longestCommonSubsequence(string s, string t) {
    int lengthS = s.size();
    int lengthT = t.size();

    vector<vector<int>> L(lengthS+1, (vector<int>(lengthT+1, 0)));

    // common subsequence matrix
    for (int i=1; i<=lengthS; i++) {
        for (int j=1; j<=lengthT; j++) {
            if (s[i-1] == t[j-1]) {
                L[i][j] = L[i-1][j-1]+1;
                continue;
            }
            L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    for (int i = 0; i < L.size(); i++)
    {
        for (int j = 0; j < L[i].size(); j++)
        {
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }
    int index = L[lengthS][lengthT];
    int i= lengthS;
    int j = lengthT;
    string lcs;

    // backtracking common subsequence matrix
    while (i >0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            lcs.push_back(s[i-1]);
            i--;
            j--;
            index--;
            continue;
        }
        if (L[i-1][j] > L[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    cout<<lcs<<endl;
    return 0;
};
int longestCommonSubsequenceUsingRecursion(string s, string t, int i, int j) {
    if (s[i] == '\0' || t[j] == '\0') {
        return 0;
    }
    if (s[i] == t[j]) {
        return 1+longestCommonSubsequenceUsingRecursion(s, t, i+1, j+1);
    }
    return max(longestCommonSubsequenceUsingRecursion(s, t, i+1, j), longestCommonSubsequenceUsingRecursion(s, t, i, j+1));
};

int main() {

    string s = "cbbd";
    vector<int> x;
    string t = s;
    reverse(t.begin(), t.end());
    cout<<"recursion: "<<longestCommonSubsequenceUsingRecursion(s, t, 0, 0)<<endl;
    longestCommonSubsequence(s, t);
    return 0;
}

