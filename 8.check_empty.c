#include<stdio.h>
#include"2main.h"

int hash_empty(H_table *hash)
{
     
        for (int i = 0; i < 27; i++)
        {
            if (hash[i].link!=NULL)
            {
               return 1;
            }       
        }
        return 0;
                 
}