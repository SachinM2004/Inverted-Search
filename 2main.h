#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

#define SUCCESS -1
#define FAILURE 0
#define LIST_EMPTY -2
#define EXT_FAIL -3
#define HASH_SIZE 27

typedef struct node
{
    char* f_name;
    struct node* link;
}Slist;

typedef struct sub_node
{
    char* f_name;
    int w_count;
    struct sub_node* sub_link;
}sub_node;


typedef struct main_node
{
    char* word;
    int f_count;
    sub_node* sub_node_link;
    struct main_node* main_node_link;
}main_node;

typedef struct hash_table
{
    int index;
    main_node* link;
}H_table;






int validate(char* argv[],Slist** head);
int validate_txt(char *filename);
void crete_hash(H_table* hash);
int get_index(char* word);
int file_empty(char* filename);
void Clear_db(H_table* hash);

void create_database(Slist* head,H_table* hash);
int insert_database(H_table *hash,char *filename,char *word);
void display_database(H_table *hash);
int save_database(H_table *hash,char *filename);
int hash_empty(H_table *hash);
int search(H_table *hash,char* key);
int val_update(char* u_file);
int update_db(H_table *hash,char* u_file,Slist **head);

