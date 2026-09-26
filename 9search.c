#include<stdio.h>
#include"2main.h"

int search(H_table *hash,char* key)
{
    
    if (!hash_empty(hash))
    {
    printf("ERROR: Database is empty. Please create the database first.\n");
    return LIST_EMPTY;
    }

    
    int idx=get_index(key);

        main_node* main_temp = hash[idx].link;

        while(main_temp != NULL)
        {
            if(strcmp(main_temp->word,key)==0)
            { 
                int first =1;
                sub_node* sub_temp = main_temp->sub_node_link;
                while(sub_temp != NULL)
                {

                    if(first)
                    {
                        first=0;
                        printf("\t\tThe word ""%s"" found in %d files.\n\t\tIn the file %s %d times reapeated",key,main_temp->f_count,sub_temp->f_name,sub_temp->w_count);
                        
                    }
                    else
                    {
                        printf("\n\t\tIn the file %s %d times reapeated",sub_temp->f_name,sub_temp->w_count);
                    }
                    
                sub_temp=sub_temp->sub_link;
                }
                return 1;

            }
            else
            {
                main_temp=main_temp->main_node_link;
            }

        }
        


return 0;

}