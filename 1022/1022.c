/* lightoj 1022 - Circle in Square */
#include <stdio.h>
#include <math.h>
#define pi 2*acos(0.0)
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
        int t,csn;
        while(scanf("%d",&t)==1)
        {
		csn=0;
		double r,c,sq;
		while(t--)
		{
			scanf("%lf",&r);
			c=pi*(r*r);
			sq=(r*2)*(r*2);
			csn++;
			printf("Case %d: %.2f\n",csn,sq-c);
		}
        }
	return 0;
}
