/* lightoj 1354 - IP Checking  */
#include <cstdio>

int poaa(int n,int powa)
{
	int ans=1;
	while(powa--)
	{
		ans*=n;
	}
	return ans;
}

int convaa(int n)
{
	int ans=0,powa=0;
	while(n>0)
	{
		ans+=(n%10)*(poaa(2,powa));
		n/=10;
		powa++;
	}
	return ans;
}

int main()
{
	#ifdef CLMAN
		freopen("in.txt","r",stdin);
	#endif // CLMAN
	int tc,a,b,c,d,a2,b2,c2,d2,csn;
	while(scanf("%d",&tc)==1)
	{
		csn=0;
		while(tc--)
		{
                        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
                        scanf("%d.%d.%d.%d",&a2,&b2,&c2,&d2);
                        if(a==convaa(a2) && b==convaa(b2) && c==convaa(c2) && d==convaa(d2))
                        {
				printf("Case %d: Yes\n",++csn);
                        }else
				printf("Case %d: No\n",++csn);
		}
	}
	return 0;
}
