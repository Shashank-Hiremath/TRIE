#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>
#define LEN 26
#define SIZE 100
#define MAX 100

void searchTrie()
{
    char trie_file_name[SIZE],input[MAX],word_file_name[SIZE],ch,c;
    long long int length,pos,val,i,t1,t2,cond,j;
    scanf("%s",trie_file_name);
    scanf("%s",word_file_name);

    int my_trie_fd = open(trie_file_name, O_RDWR);
       if(my_trie_fd < 0){
           printf("open error\n");
       }
       struct stat myStat = {};
       if (fstat(my_trie_fd, &myStat)){
           printf("fstat error\n");
       }
       off_t size = myStat.st_size;
       char *addr;
       addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, my_trie_fd, 0);
       if (addr == MAP_FAILED){
           printf("mmap error\n");
       }
    FILE *fp;
    fp=fopen(word_file_name,"r");
    i=0;
    c=fgetc(fp);
    while(c!=EOF)
    {
        for(length=0;c!=' ';length++,c=fgetc(fp))
            input[length]=c;
        input[length]=c;
        c=fgetc(fp);

        printf("%lld-%s\n",i,input);
        i++;
        cond=1;
        pos=0;
        val=0;
        t2=0;
        while((input[pos]!=' ')&&cond)
        {		
            val = input[pos] - 'a';
            t1=(pow(LEN, pos+1)-1)/(LEN-1) - 1;
            t2= 26*t2 + val;
            if((val<26)&&(val>=0))
            {
                cond=addr[t1+t2]-'0';
                printf("%c\t%lld\t",input[pos],t1+t2);
                pos++;
            }
            else
            {
                printf("Value not in range a to z");
                return;
            }
            for(j=0;j<26;j++)
                printf("%c",addr[t1+t2-val+j]);
            printf("\n");
        }
	(cond==2)?printf("Yes\n"):printf("No\n");
    }
}

