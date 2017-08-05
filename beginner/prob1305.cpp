#include <cstdio>
#include <cstdlib>
int main()
{
	//freopen("in.txt", "r", stdin);
	int tc,x1,x2,x3,y1,y2,y3,x4,y4,ans,csn;
	while(scanf("%d",&tc)==1)
	{
		csn=0;
		while(tc--)
		{
			scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
			ans=abs(((x1*y2)+(x2*y3)+(x3*y1))-((x1*y3)+(x3*y2)+(x2*y1)));
			x4=x1-x2+x3;
			y4=y1-y2+y3;
			printf("Case %d: %d %d %d\n",++csn,x4,y4,ans);
		}
	}
	return 0;
}
