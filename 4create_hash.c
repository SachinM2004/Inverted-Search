#include<stdio.h>
#include"2main.h"

void crete_hash(H_table* hash)
{
    for(int i=0; i<HASH_SIZE; i++)
    {
        hash[i].index = i;
        hash[i].link = NULL; 
    }
}

int get_index(char* word)
{
    char ch = tolower(word[0]);

    if(ch>='a' && ch<='z')
    return ch -'a';

    return 26;
}

