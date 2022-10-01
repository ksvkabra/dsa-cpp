
#include <bits/stdc++.h>
using namespace std;
 
void search(string& pat, string& txt)
{
    /*finding lengths of strings pat and txt*/
    int n = txt.length(), m = pat.length();
    /*string sortedpat stores the sorted version of pat*/
    string sortedpat = pat;
    sort(sortedpat.begin(), sortedpat.end());
    /*temp for storing the substring of length equal to
     * pat*/
    string temp;
    for (int i = 0; i <= n - m; i++) {
        temp = "";
        for (int k = i; k < m + i; k++)
            temp.push_back(txt[k]);
        sort(temp.begin(), temp.end());
        /*checking whether sorted versions are equal or
         * not*/
        if (sortedpat == temp)
            cout << "Found at Index " << i << endl;
    }
}
int main()
 
{
    string txt = "BACDGABCDA";
    string pat = "ABCD";
    search(pat, txt);
    return 0;
}
