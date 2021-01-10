#include <stdio.h>
int main()
{
    /*freopen("in.txt", "r", stdin);*/
    int x1,x2,y1,y2,cx,cy;
    int tc,cn,cas;
    while(scanf("%d",&tc)==1)
    {
        cas=0;
        while(tc--)
        {
            cas++;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            scanf("%d",&cn);
            printf("Case %d:\n",cas);
            while(cn--)
            {
                scanf("%d %d", &cx, &cy);
                if((cy>y1 && cy<y2)&&(cx<x2 && cx>x1))
                {
                    printf("Yes\n");
                }else printf("No\n");
            }
        }
    }
    return 0;
}
