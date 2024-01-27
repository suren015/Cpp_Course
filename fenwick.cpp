#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int bit[N];

/*----Binary Index Trees :: Type(1) - updating ith index by x , Type(2) - Sum from l to r ----*/

void update(int i, int x)
{
    for (; i < N; i += (i & -i))
        bit[i] += x;
}
int sum(int i)
{
    int ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}
void solve(){
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n ;i++){
        cin >> a[i + 1];
    }
    for (int i = 1; i <= n;i++){
        update(i, a[i]);
    }

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type==1){
            int idx, x;
            cin >> idx >> x;
            update(idx + 1, x - a[idx + 1]);
            a[idx + 1] = x;
        }else{
            int l, r;
            cin >> l >> r;
            l = l + 1;
            r = r + 1;
            cout << sum(r) - sum(l-1) << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}