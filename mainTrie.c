#include "include1.h"

int main()
{
    char choice;
    scanf("%c",&choice);
    switch(choice){
        case 'c':
        createTrie();
        break;
        case 'i':
        insertTrie();
        break;
        case 's':
        searchTrie();
        break;
        case 'd':
        deleteTrie();
        break;
    }
    return 0;
}

