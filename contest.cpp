#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
const int N = 2e5;

/* ...............................................DEFINE...................................................*/

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back
#define in(a)                          \
    for (int i = 0; i < a.size(); i++) \
        cin >> a[i];
#define out(a)                         \
    for (int i = 0; i < a.size(); i++) \
        cout << a[i] << " ";
#define precise(x) cout << fixed << setprecision(10) << x << endl;
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vpii vector<pair<int, int>>
#define all(c) c.begin(), c.end()

/* ...............................................SOLVE....................................................*/

void solve()
{
    int x, n;
    cin >> x >> n;
    if (x % n == 0)
    {
        cout << x / n << endl;
    }
    else
    {
        int y = x / n;
        if (x % y == 0)
        {
            cout << y << endl;
        }
        else
        {
            vi v;
            for (int i = 1; i * i <= x; i++)
            {
                if (x % i == 0)
                {
                    if (x / i == i)
                    {
                        v.push_back(i);
                    }
                    else
                    {
                        v.push_back(i);
                        v.push_back(x / i);
                    }
                }
            }
            sort(v.begin(), v.end());
            int idx = lower_bound(v.begin(), v.end(), x / n) - v.begin();
            if (idx > v.size() || v[idx] > x / n)
            {
                idx--;
            }
            cout << v[idx] << endl;
        }
    }
}

/* .................................... MAIN FUNCTION.....................................................*/

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
