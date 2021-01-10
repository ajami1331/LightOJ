#include <stdio.h>

int main()
{
    short t;
    int a,b,c;
    short i=0;
    scanf("%hd",&t);
    while(t>0)
    {
        i++;
        scanf("%d%d%d", &a, &b, &c);
        if(((a*a)+(b*b))==(c*c))
        {
            printf("Case %d: yes\n", i);
        }
        else if(((a*a)+(c*c))==(b*b))
        {
            printf("Case %d: yes\n", i);
        }
        else if(((c*c)+(b*b))==(a*a))
        {
            printf("Case %d: yes\n", i);
        }
        else
        {
            printf("Case %d: no\n", i);
        }
        t--;
    }
    return 0;
}
