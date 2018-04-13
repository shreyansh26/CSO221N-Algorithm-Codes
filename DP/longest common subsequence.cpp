#include <bits/stdc++.h>

using namespace std;

int main() {
    int i,j,n,k,l,m;
    cout<<"Enter the first string: ";
    string a,b;
    cin>>a;
    cout<<"Enter the second string: ";
    cin>>b;
    n = a.length();
    m = b.length();

    int dp[m+1][n+1];

    for(i=0;i<m+1;i++)
        dp[i][0]=0;

    for(j=0;j<n+1;j++)
        dp[0][j]=0;

    for(i=1;i<m+1;i++) {
        for(j=1;j<n+1;j++) {
            if(b[i-1]!=a[j-1]) {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
            else {
                dp[i][j]=dp[i-1][j-1]+1;
            }
        }
    }
    cout<<endl;
    cout<<"The length of the longest common subsequence is: ";
    cout<<dp[m][n]<<endl;

    int index = dp[m][n];

    char lcs[index+1];
    lcs[index] = '\0'; 
 
    i = n, j = m;
    while (i>0 && j>0) {
       if (a[i-1] == b[j-1]) {
           lcs[index-1] = a[i-1]; 
           i--; j--; index--;  
       }

       else if (dp[i-1][j] > dp[i][j-1])
          i--;
       else
          j--;
    }
 
    cout << "LCS of " << a << " and " << b << " is " << lcs << endl;
    return 0;
}
