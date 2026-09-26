#include<stdio.h>
#include"2main.h"

int validate_txt(char *filename)
{
    int len = strlen(filename);

    if (len < 4)
        return FAILURE;

    if (strcmp(filename + len - 4, ".txt") == 0)
        return SUCCESS;

    return FAILURE;
}

int file_empty(char* filename)
{
        FILE *fp = fopen(filename, "r");
        if (fp == NULL)
        {
            return 1;
        }

        fseek(fp,0,SEEK_END);
        if(ftell(fp)==0)
        {
            return 1;
        }
        else
        return FAILURE;
}

int validate(char* argv[],Slist** head)
{
    int i=1;
    while(argv[i])
    {

        //to check .txt file
        if (validate_txt(argv[i]) == FAILURE)
        {
            printf("%s : Invalid file format\n", argv[i]);
            i++;
            continue;
        }


        //check it exist in same directory or not
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("%s does not exist\n", argv[i]);
            i++;
            continue;
        }

        //check empty
        fseek(fp,0,SEEK_END);
        if(ftell(fp)==0)
        {
            printf("%s is empty\n", argv[i]);
            fclose(fp);
            i++;
            continue;
        }

        //to check duplicate
        int duplicate=0;
        Slist *temp = *head;

        while(temp)
        {
            if(strcmp(temp->f_name,argv[i])==0)
            {
                duplicate = 1;
                break;
            }
            temp=temp->link;
        }

        if(duplicate)
        {
            printf("%s : Duplicate file\n", argv[i]);
            i++;
            continue;
        }



            //to insert linked list
            Slist* new = malloc(sizeof(Slist));

            if(new==NULL)
            {
                return FAILURE;
            }

            new->f_name = argv[i];
            new->link = NULL;

            if(*head==NULL)
            {
                *head=new;
            }
            else
            {
                Slist* temp = *head;

                    while(temp->link!=NULL)
                    temp=temp->link;
                    
                temp->link = new;
            }
             printf("%s : Added successfully\n", argv[i]);
    
        i++;
    }

        return SUCCESS;

}
