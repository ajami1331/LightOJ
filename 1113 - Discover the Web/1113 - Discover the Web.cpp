#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 2e5 + 1;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t;
    string s1, s2, cur;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        stack < string > bk, fr;
        printf( "Case %d:\n", cs );
        cur = "http://www.lightoj.com/";
        while( cin >> s1 ) {
            if( s1 == "QUIT" ) break;
            if( s1 == "VISIT" ) {
                cin >> s2;
                if( !cur.empty() ) bk.push( cur );
                cur = s2;
                cout << cur << "\n";
                while( !fr.empty() ) fr.pop();
            }
            else if( s1 == "BACK" ) {
                if( bk.empty() ) {
                    cout << "Ignored\n";
                } else {
                    fr.push( cur );
                    cur = bk.top();
                    bk.pop();
                    cout << cur << "\n";
                }
            }
            else if( s1 == "FORWARD" ) {
                if( fr.empty() ) {
                    cout << "Ignored\n";
                } else {
                    bk.push( cur );
                    cur = fr.top();
                    fr.pop();
                    cout << cur << "\n";
                }
            }
        }
    }
    return 0;
}
