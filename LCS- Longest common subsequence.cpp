#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS_length(const vector<int>& a, const vector<int>& b,int m,int n) {

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    
    int m,n;
    cin>>m>>n;
    int in;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<m;i++) {
        cin>>in;
        a.push_back(in);
    }
    for(int i=0;i<n;i++) {
        cin>>in;
        b.push_back(in);
    }

    int result = LCS_length(a, b,m,n);

    cout<< result << endl;

    return 0;
}
