#include<stdio.h>
#include"2main.h"


void Clear_db(H_table *hash)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        main_node *temp = hash[i].link;

        while (temp != NULL)
        {
            main_node *main_next = temp->main_node_link;

            sub_node *sub = temp->sub_node_link;
            while (sub != NULL)
            {
                sub_node *sub_next = sub->sub_link;

                free(sub->f_name);
                free(sub);

                sub = sub_next;
            }

            free(temp->word);
            free(temp);

            temp = main_next;
        }

        hash[i].link = NULL;
    }
}