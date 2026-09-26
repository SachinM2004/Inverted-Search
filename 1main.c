#include<stdio.h>
#include"2main.h"

int main(int argc,char* argv[])
{

    if (argc < 2)
    {
        printf("Usage: ./a.out <file1.txt> <file2.txt> ...\n");
        return 1;
    }


    Slist* head = NULL;

    if(validate(argv,&head)==FAILURE)
    {
        printf("ERROR:\n");
        return 0;
    }

    H_table hash[HASH_SIZE];
    crete_hash(hash);

    printf("\t\tSuccessfully Files are Stored\n");

    int c=1;
    int opt;
    do{
    
    printf("\n1.Create Data-Base\n2.Save\n3.Search\n4.Display\n5.Update\n6.Clear database\n7.Exit\n");
    scanf("%d",&opt);

    switch(opt)
    {

    case 1:
    {
        if(c)
        {
        create_database(head,hash);
        printf("\t\t::Databse Created Successfully::\n");
        c=0;
        }
        else
        {
            printf("\t\tWe cannot perform Create data base twice\n");
        }
    }
    break;
    case 2:
    {
        char file[20];
        int i;
        do{
        printf("Enter the file to backup(ex:abc.txt):");
        scanf("%s",file);
      
             i=0;
            if(save_database(hash,file)==0)
            {
                i=1;
            }
            else
            {
                printf("\nData saved to %s file successfully\n",file);
            }
        }while(i);
    }
    break;

    case 3:
    {
        char key[50];
        printf("Enter the word to search:\n");
        scanf("%s",key);
        if(search(hash,key)==0)
        {
            printf("\t\tData not found!!\n");
        }
    }
    break;


    case 4:
    {
        display_database(hash);
    }
    break;
    case 5:
    {
        if (hash_empty(hash))
        {
            printf("\tERROR: Database is not empty. we can not update.\n");
        }
        else
        {
            
            char u_file[20];
            printf("Enter file name to update Database:");
            scanf("%s",u_file);
            int val=1;
            do{
                if(val_update(u_file)==0)
                {
                    getchar();
                    val = 0;
                    printf("\tERROR : Enter again correct extisting file name:");
                    scanf("%s",u_file);
                }
                else
                {
                    val = 1;
                }
            }while(val!=1);



            update_db(hash,u_file,&head);
            printf("\t!!!!Database Updated Successfully!!!!\n");
        }
    }
     
    
        break;

    case 6:
    {
        Clear_db(hash);
    }
    break;

        case 7:
    {
        return 0;
    }
    break;

    default :
    {
        printf("invalid choice\n");
        return 0;
    }
}
}while(opt!=7);

}