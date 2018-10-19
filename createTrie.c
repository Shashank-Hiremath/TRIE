#include<stdio.h>
#include<math.h>
#define LEN 26
#define SIZE 100

void createTrie()
{
    long long int pos,length,i;
    char name[SIZE];

    scanf("%lld%s",&length,name);
    printf("length=%lld\n",length);
    if(length>5)
        printf("length greater than 5. No file created\n");
    else
    {
        FILE *fp=fopen(name,"w");
        for(pos=1;pos<=length;pos++)
            {
                for(i=0;i<pow(LEN,pos);i++)
                    fputc('0',fp);
                printf("%lld\n",pos);
            }
        fclose(fp);
    }
    
}

