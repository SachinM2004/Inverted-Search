#include<stdio.h>
#include"2main.h"    


void create_database(Slist* head,H_table* hash)
{
    char word[100];

    while(head != NULL)
    {
         FILE* fp = fopen(head->f_name,"r");

         if(fp==NULL)
         {
            head = head->link;
            continue;
         }

        while (fscanf(fp, "%99s", word) != EOF)
        {
            int index = get_index(word);
            insert_database(hash,head->f_name,word);
        }

        fclose(fp);

        head = head->link;
    }
}

int insert_database(H_table *hash,char *filename,char *word)
{
    int index = get_index(word);

    //when table link if NULL
    if(hash[index].link == NULL)
    {
        main_node* new = malloc(sizeof(main_node));

        if(new==NULL)
        {
            return 0;
        }

        new->word = malloc(strlen(word)+1);
        if (new->word == NULL)
        {
            free(new);
            return FAILURE;
        }
        strcpy(new->word, word);
        new->f_count = 1;
        new->main_node_link = NULL;

        sub_node* new_sub = malloc(sizeof(sub_node));
       
        if(new_sub==NULL)
        {
            free(new->word);
            free(new);
            return 0;
        }

        new_sub->f_name = malloc(strlen(filename) + 1);
        if (new_sub->f_name == NULL)
        {
            free(new_sub);
            free(new->word);
            free(new);
            return FAILURE;
        }
        strcpy(new_sub->f_name, filename);
        new_sub->w_count = 1;
        new_sub->sub_link = NULL;

        new->sub_node_link = new_sub;
        hash[index].link = new;

        return SUCCESS;
        
    }
    else    
    {
        //main node is present travrese main node find 
        //if the word present then increse the w_count

        main_node* main_temp=hash[index].link;

        while(main_temp != NULL)
        {
            if(strcmp(main_temp->word,word)==0)  //word found
            {
                sub_node* sub_temp = main_temp->sub_node_link;
                
                while(sub_temp != NULL)
                {
                     if(strcmp(sub_temp->f_name,filename)==0) //file found 
                     {
                        sub_temp->w_count++;                    //word present in same file multiple time
                        return SUCCESS;
                     }

                    if (sub_temp->sub_link == NULL)
                    break;

                    sub_temp=sub_temp->sub_link; //travers subnode
                }
            //case3 //if the word is present in diffrent file increse f_count

            sub_node* new_sub = malloc(sizeof(sub_node));

            if(new_sub==NULL)
            {
                free(new_sub);
                return FAILURE;
            }

            new_sub->f_name = malloc(strlen(filename)+1);
            strcpy(new_sub->f_name,filename);
            new_sub->w_count = 1;
            new_sub->sub_link=NULL;

            sub_temp->sub_link = new_sub;
            main_temp->f_count++;
            return SUCCESS;

        }
            main_temp=main_temp->main_node_link;//traverse main node
        }

         //if new word coms (diff) then crete new main node, sub and insert last 

            main_node* new = malloc(sizeof(main_node));

            if(new==NULL)
            {
                return 0;
            }

            new->word = malloc(strlen(word)+1);

            if(new->word == NULL)
            {
                free(new);
                return FAILURE;
            }

            strcpy(new->word, word);
            new->f_count = 1;
            new->main_node_link = NULL;

            sub_node* new_sub = malloc(sizeof(sub_node));
        
            if(new_sub==NULL)
            {
                free(new->word);
                free(new);
                return 0;
            }

            new_sub->f_name = malloc(strlen(filename) + 1);

            if(new_sub->f_name == NULL)
            {
                free(new_sub);
                free(new->word);
                free(new);
                return FAILURE;
            }

            strcpy(new_sub->f_name, filename);
            new_sub->w_count = 1;
            new_sub->sub_link = NULL;


            main_node *prev = NULL;
            main_node *main_temp2 = hash[index].link;

            while (main_temp2 != NULL)           //traverse till last node and insert
            {
                prev = main_temp2;
                main_temp2 = main_temp2->main_node_link;
            }

       

            new->sub_node_link = new_sub;
            new->main_node_link = NULL;
            prev->main_node_link = new;

            return SUCCESS;


    }
       
    return FAILURE;

}