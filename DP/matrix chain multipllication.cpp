#include<bits/stdc++.h>
#define ll long long

using namespace std;

int c[10000][10000];

void f(ll l, ll r) {
    if(l==r) {
        cout<<"A"<<l;
        return;
    }  
    ll k = c[l][r];
    cout<<'(';
    f(l, k);
    cout<<")(";
    f(k+1, r);
    cout<<')';
    cout<<endl;
}

int main() {
    int i,j,n,k,l;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    vector<pair<int,int> >val;
    cout<<"Enter the dimensions of matrices in chain form"<<endl;
    for(i=0;i<n;i++) {
       cout<<"Enter the dimensions of matrix "<<i+1<<": ";
        cin>>l>>k;
        val.push_back(make_pair(l,k));
    }

    int dp[n][n];

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++)
            dp[i][j]=INT_MAX;
    }
    for(i=0;i<n;i++)
        dp[i][i]=0;

    for(i=1; i<=n-1; i++) {
        for(j=0; j<=n-i-1; j++) {
            for(k=j; k<=j+i-1; k++) {
                dp[j][j+i] = min(dp[j][i+j], dp[j][k]+dp[k+1][i+j]+val[j].first*val[k].second*val[j+i].second);
                c[j][j+i] = k;
            }
        }
    }

    cout<<"The minimum cost for matrix chain multiplication is: ";
    cout<<dp[0][n-1]<<endl;
    f(0, n-1);
    return 0;
}
