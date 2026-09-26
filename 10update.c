#include<stdio.h>
#include"2main.h"

int update_db(H_table *hash,char* u_file,Slist **flist)
{
    FILE* fp = fopen(u_file,"r");
    if(fp ==NULL)
    {
        fclose(fp);
        return FAILURE;
    }

    char line[100];

    while(fgets(line,sizeof(line),fp))
    {
        char *token = strtok(line,";");

        int index = atoi(token+1);

        char word[50];
        token = strtok(NULL,";");
        strcpy(word,token);


        token = strtok(NULL,";");
        int file_count = atoi(token);

        
        main_node* new = malloc(sizeof(main_node)); // create main
        if(new==NULL)
        {
            fclose(fp);
            return FAILURE;
        }

        new->word = malloc(strlen(word)+1);
        if (new->word == NULL)
        {
            free(new);
            return FAILURE;
        }
        strcpy(new->word, word);
        new->f_count = file_count;
        new->main_node_link = NULL;
        new->sub_node_link = NULL;

        sub_node *head = NULL;
        sub_node *tail = NULL;

        for(int i=0; i<file_count; i++)
        {
             
            char fi_name[20];
            token = strtok(NULL,";");
            strcpy(fi_name,token);

            token = strtok(NULL,";");
            int word_count = atoi(token);

        sub_node *new_sub = malloc(sizeof(sub_node)); // create sub
        if(new_sub==NULL)
        {
            fclose(fp);
            return FAILURE;
        }

            new_sub->f_name = malloc(strlen(fi_name) + 1);
            if (new_sub->f_name == NULL)
            {
                free(new_sub);
                free(new->word);
                free(new);
                return FAILURE;
            }

            strcpy(new_sub->f_name, fi_name);
            new_sub->w_count = word_count;
            new_sub->sub_link = NULL;


            if (head == NULL)
            {
                head = new_sub;
                tail = new_sub;
            }
            else
            {
                tail->sub_link = new_sub;
                tail = new_sub;
            }


            //this section for deleting same files from linked list

            if(*flist!=NULL && strcmp((*flist)->f_name, fi_name) == 0)//if file in first node if found delete file from list
            {
                 Slist* temp1 = *flist;
                 *flist=(*flist)->link;
                 free(temp1);
            }
            Slist* temp = *flist;
           while(temp != NULL && temp->link != NULL)//compare till end list if found delete file from list
            {
                if(strcmp(temp->link->f_name, fi_name) == 0)
                {
                    Slist* temp1 = temp->link;
                    temp->link = temp1->link;
                    free(temp1);
                }
                else
                temp = temp->link;
            }




        }
        new->sub_node_link = head;

            
            if (hash[index].link == NULL)
            hash[index].link = new;
            else
            {
               main_node* temp = hash[index].link;


                while(temp->main_node_link)
                    temp = temp->main_node_link;

                temp->main_node_link = new;
            }
    }
    fclose(fp);
    return SUCCESS;
}