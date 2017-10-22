#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

inline int RI() {
    int  ret = 0, flag = 1,ip = gc();
    for(; ip < 48 || ip > 57; ip = gc()) {
        if(ip == 45) {
            flag = -1;
            ip = gc();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = gc())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}

inline void writeInt (int n)
{
    int NN = n, rev, count = 0;
    rev = NN;
    if (NN == 0) { pc('0');  return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (NN != 0) { rev = (rev<<3) + (rev<<1) + NN % 10; NN /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

const int sz = 1e5 + 10;
typedef long long ll;
struct info {
    int prop, sum;
} tree[ sz * 3 ];
 
ll ar[sz];
 
void build( int node, int b, int e ) {
    tree[node].sum = 0;
    tree[node].prop = -1ll;
    if( b == e ) {
        return;
    }
    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;
    build( left, b, mid );
    build( right, mid + 1, e );
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void propagate( int node, int b, int e ) {
    if( tree[node].prop != -1 ) {
        tree[node].sum = ( e - b + 1 ) * tree[node].prop;
        if( b != e ) {
            tree[node*2].prop = tree[node].prop;
            tree[node*2+1].prop = tree[node].prop;
        }
        tree[node].prop = -1;
    }
}

void update( int node, int b, int e, int l, int r, int x ) {
    propagate( node, b, e );
    if( r < b || e < l ) return;
    if( b >= l && e <= r ) {
        tree[node].sum = ( e - b + 1 ) * x;
        // cerr << node << " " << b << " " << e << " " << l << " " << r << " " << tree[node].sum << "up\n";
        if( b != e ) {
            //cerr << b << " " << e << "\n";
            tree[node*2].prop = x;
            tree[node*2+1].prop = x;
        }
        return;
    }
    int left = node << 1;
    int right = left | 1;
    int mid = ( b + e ) >> 1;
    update( left, b, mid, l, r, x );
    update( right, mid + 1, e, l, r, x );
    tree[node].sum = tree[left].sum + tree[right].sum;
}
 
int query( int node, int b, int e, int l, int r ) {
    // cerr << node << " " << b << " " << e << " " << l << " " << r << " " << tree[node].prop << "\n";
    propagate( node, b, e );
    if( r < b || e < l ) return 0;
    if( b >= l && e <= r ) {
        // cerr << node << " " << b << " " << e << " " << l << " " << r << " " << tree[node].sum << "\n";
        return tree[node].sum;
    }
 
    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;
 
    int p1 = query( left, b, mid, l, r );
    int p2 = query( right, mid + 1, e, l, r );
 
    return p1 + p2;
}
 
int main() {
    int t, n, q;
    int qu, gc, dw;
    int ty, x, y, v;
    t = RI();
    for( int cs=1; cs<=t; cs++ ) {
        n = RI(); q = RI();
        // cerr << n << " " << q << '\n';
        build( 1, 0, n - 1 );
        // printf( "Case %d:\n", cs );
        pc( 'C' );
        pc( 'a' );
        pc( 's' );
        pc( 'e' );
        pc( ' ' );
        writeInt( cs );
        pc( ':' );
        pc( '\n' );
        // cerr << "case " << cs << "\n";
        for( int i=0; i<q; i++ ) {
            ty = RI(); x = RI(); y = RI();
            // cerr << ty << " " << x << " " << y;
            if( ty == 1 ) {
                v = RI();
                // cerr << v << "\n";
                update( 1, 0, n - 1, x, y, v );
            }
            else {
                // cerr << "\n";
                qu = query( 1, 0, n - 1, x, y );
                dw = y - x + 1;
                gc = __gcd( dw, qu );
                //cerr << qu << " " << dw << " " << gc << "\n";
                qu /= gc;
                dw /= gc;
                writeInt( qu );
                if( qu != 0 && dw != 1 ) {
                    pc( '/' );
                    writeInt( dw );
                }
                pc( '\n' );
            }
        }
    }
    return 0;
}
