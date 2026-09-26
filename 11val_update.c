 #include<stdio.h>
#include"2main.h"

 int val_update(char* u_file)
 {
    if(validate_txt(u_file)==0)
    return 0;

    

    FILE *fp = fopen(u_file, "r");
        if (fp == NULL)
        {
            printf("%s does not exist\n", u_file);
           return 0;
        }

        
        if(fgetc(fp) != '#') //check first element #
        return 0;

        //check empty
        fseek(fp,0,SEEK_END);

         if(ftell(fp)<17)       //if the file not contain base file min lenth
         return 0;

        if(ftell(fp)==0)
        {
            printf("%s is empty\n", u_file);
            return 0;
        }
        if(fgetc(fp) != '#') //check last element #
        
        rewind(fp);

        int ch;
        while((ch=fgetc(fp))!=EOF)
        {
            if (ch == ' ' || ch == '\t')
            return 0; 
        }


        return 1;



 }
