#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e4 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n, p, q, ans;
char s[sz];
const int MAXN = sz;
struct suffix {
        int index;
        int rank[2];
        bool operator < ( const suffix &other ) const {
                if( this->rank[0] == other.rank[0] ) {
                        return this->rank[1] < other.rank[1];
                }
                return this->rank[0] < other.rank[0];
        }
};

vector < int > buildSuffixArray( const string &s ) {
        int n = int( s.size() );
        vector < int > sufArray;
        vector < suffix > suffixes( n );
        for( int i=0; i<n; i++ ) {
                suffixes[i].index = i;
                suffixes[i].rank[0] = s[i];
                suffixes[i].rank[1] = i + 1 < n ? s[i+1] : -1;
        }
        vector < int > ind( n );
        int nextIndex, rank, prev_rank, n_2 = n << 1;
        sort( suffixes.begin(), suffixes.end() );
        for( int k=4; k<n_2; k<<=1 ) {
                rank = 0;
                prev_rank = suffixes[0].rank[0];
                suffixes[0].rank[0] = rank;
                ind[ suffixes[0].index ] = 0;
                for( int i=1; i<n; i++ ) {
                        if( suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1] ) {
                                prev_rank = suffixes[i].rank[0];
                                suffixes[i].rank[0] = rank;
                        } else {
                                prev_rank = suffixes[i].rank[0];
                                suffixes[i].rank[0] = ++rank;
                        }
                        ind[ suffixes[i].index ] = i;
                }
                for( int i=0; i<n; i++ ) {
                        nextIndex = suffixes[i].index + k / 2;
                        suffixes[i].rank[1] = nextIndex < n ? suffixes[ ind[ nextIndex ] ].rank[0] : -1;
                }
                sort( suffixes.begin(), suffixes.end() );
        }
        for( const suffix suf: suffixes ) {
                sufArray.push_back( suf.index );
        }
        return sufArray;
}

vector<int> kasai( const string& s, const vector<int> &sa ) {
        int n=s.size(),k=0;
        vector<int> lcp(n,0);
        vector<int> rank(n,0);

        for(int i=0; i<n; i++) rank[sa[i]]=i;

        for(int i=0; i<n; i++, k?k--:0) {
                if(rank[i]==n-1) {
                        k=0;
                        continue;
                }
                int j=sa[rank[i]+1];
                while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
                lcp[rank[i]]=k;
        }
        return lcp;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%s", s );

                n = strlen( s );

                scanf( "%d %d", &p, &q );

                ans = 0;

                vector < int > sa = buildSuffixArray( s );

                vector < int > lcp = kasai( s, sa );

                for( int i=0; i<n; i++ ) {
                        ans += max( min( n - sa[i], q ) - max( lcp[i], p - 1 ), 0 );
                }

                printf( "Case %d: %d\n", cs, ans );
        }

        return 0;
}
