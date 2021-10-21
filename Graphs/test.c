#include <stdio.h>
#include <unistd.h>

int main()
{
    if(!fork()){
        int a = 0, b=1,n;
        scanf("%d",&n);
        if(n>1){
            printf("\n%d %d ",a,b);
            for(int i = 2;i<n;i++){
                int c = a+b;
                printf("%d",c);
                a = b;
                b = c;
            }
        }
        else if(n == 0)
            return 0;
        else if(n == 1)
            printf("0");
        else
            printf("It is a negative number");
    }
    return 0;
}