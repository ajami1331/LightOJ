#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 2e5 + 1;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    map < string, ll > mp;
    mp["January"]=0;
    mp["February"]=1;
    mp["March"]=2;
    mp["April"]=3;
    mp["May"]=4;
    mp["June"]=5;
    mp["July"]=6;
    mp["August"]=7;
    mp["September"]=8;
    mp["October"]=9;
    mp["November"]=10;
    mp["December"]=11;
    ll d1, m1, y1, d2, m2, y2, ans;
    int t;
    string s1, s2;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        cin >> s1; scanf( "%lld,%lld", &d1, &y1 ); m1 = mp[s1];
        cin >> s2; scanf( "%lld,%lld", &d2, &y2 ); m2 = mp[s2];
//        cerr << s1 << "," << d1 << " " << y1 << "\n";
//        cerr << s2 << "," << d2 << " " << y2 << "\n";
        if( m1 > 1 ) y1++;
        if( !m2 || ( m2 == 1 && d2 < 29 ) ) y2--;
        y1--;
        ans = y2 / 4 - y1 / 4;
        ans-=( y2 / 100 - y1 / 100);
        ans+=( y2 / 400 - y1 / 400 );
        printf( "Case %d: %lld\n", cs, ans );
    }
    return 0;
}
