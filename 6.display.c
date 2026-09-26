#include<stdio.h>
#include"2main.h"


void display_database(H_table *hash)
{
   

    if (!hash_empty(hash))
    {
    printf("\t\tERROR: Database is empty. Please create the database first.\n");
    }
    else
    {
        printf("  \t\t\t-::DATABASE::-\n");
    printf("----------------------------------------------------------------------------\n");
    printf("| Index | %-15s | %-10s | %-20s | %-10s |\n",
           "Word", "File Count", "File Name", "Word Count");
    printf("----------------------------------------------------------------------------\n");

    
    for(int i=0; i<27; i++)
    {
        if(hash[i].link==0)
        continue;
        
        main_node* main_temp = hash[i].link;
        while(main_temp != NULL)
        {
          
            int first =1;
            
            sub_node* sub_temp = main_temp->sub_node_link;
            while(sub_temp != NULL)
            {
                if(first)
                {
                    first=0;
                    printf("| %-5d | %-15s | %-10d | %-20s | %-10d |\n",i,main_temp->word,main_temp->f_count,sub_temp->f_name,sub_temp->w_count );
                }
                else
                {
                      printf("| %-5s | %-15s | %-10s | %-20s | %-10d |\n", "", "","",sub_temp->f_name, sub_temp->w_count);                  
                }
                
                sub_temp = sub_temp->sub_link;

            }

            main_temp = main_temp->main_node_link;
        }
    }
    printf("----------------------------------------------------------------------------\n");
}

}