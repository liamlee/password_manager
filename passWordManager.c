#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "sqlite3.h"

//#include<unistd.h> for linux

/*typedef struct account
{
    char user_name[20];
    char pass_word[20];
    char remark[50];
}NODE;
*/
void exec_sql(const char *sql,boolean is_query);
int call_back(void *para ,int n_col,char **col_value,char **col_name);
void save_pass_word();
void get_pass_word();
void update_pass_word();
char* code_user_name(char *);       /*加密用户名*/
char* code_pass_word(char *);       /*加密密码*/
char* decode_pass_word(char *);     /*解密密码*/
void user_face();
void deal_chioce();
void print_all();
//int count = 0;
//NODE acct_node[100];

int main()
{
    user_face();

    while(1)
    {
        deal_chioce();
    }

    return 0;
}

void deal_chioce()
{
    char chioce = 0;
    scanf("%c",&chioce);
    getchar();

    switch(chioce)
    {
        case '1':
            save_pass_word();
            break;
        case '2':
            get_pass_word();
            break;
        case '3':
            update_pass_word();
            break;
        case '0':
            exit(0);
        default:
            system("cls");
            user_face();
            break;
    }
}

void exec_sql(const char *sql,boolean is_query)
{
    sqlite3 *db = NULL;
    char *errmsg;
    int result = sqlite3_open("data/test.db",&db);
    if(result != SQLITE_OK)
    {
        printf("Open failed!\n");
        return ;
    }

    if(is_query)
    {
        result = sqlite3_exec(db,sql,call_back,0,&errmsg);
    }
    else
    {
        result = sqlite3_exec(db,sql,0,0,&errmsg);
    }

    //printf("%d %s\n",result,errmsg);

    if(result != SQLITE_OK)
    {
        sqlite3_close(db);
        printf("错误代码：%d,错误信息：%s\n",result,errmsg);
        sqlite3_free(errmsg);
        return ;
    }
    sqlite3_close(db);
}

//每查到一条记录调用一次该函数
int call_back(void *para ,int n_col,char **col_value,char **col_name)
{
    int i;
    printf("共%d个字段\n",n_col);
    printf("字段名 : 字段值\n");
    for(i=0;i<n_col;i++)
    {
        //decode_pass_word();
        printf("%s : %s\n",col_name[i],col_value[i]);
    }
    return 0;
}

void save_pass_word()
{
    char insert_sql[10240];
    char user_name[20];
    char pass_word[20];
    char remark[50];
    boolean is_query = FALSE;

    printf("Input your username:\n");
    gets(user_name);
    //code_user_name(user_name);

    printf("Input your password:\n");
    gets(pass_word);
    //code_pass_word(pass_word);

    printf("Remark the account!:\n");
    gets(remark);

    /*printf("username %s ",user_name);
    printf("password %s ",pass_word);
    printf("Remark %s\n ",remark);*/

    sprintf(insert_sql,"insert into account_info values('%s','%s','%s')",user_name,pass_word,remark);
    //printf("%s\n",insert_sql);

    exec_sql(insert_sql,is_query);

    printf("Save successful!\n");
    Sleep(2000);
    system("cls");
    user_face();
}

void get_pass_word()
{
    //printf("Here you can find your password which you've forget!\n");
    char name[20];
    char query_sql[10240];
    boolean is_query = TRUE;

    gets(name);
    //code_user_name(name);

    sprintf(query_sql,"select * from account_info where user_name = '%s'",name);
    exec_sql(query_sql,is_query);
    //printf("%s\n",query_sql);

    Sleep(6000);
    system("cls");
    user_face();
}

void update_pass_word()
{
    char update_sql[10240];
    char user_name[20];
    char pass_word[20];
    boolean is_query = FALSE;

    printf("user_name: ");
    gets(user_name);
    //code_user_name(user_name);
    printf("New password: ");
    gets(pass_word);
    //code_pass_word(pass_word);

    sprintf(update_sql,"update account_info set pass_word = '%s' where user_name = '%s' ",pass_word,user_name);
    //printf("%s\n",update_sql);

    exec_sql(update_sql,is_query);

    printf("Update successful!\n");
    Sleep(3000);
    system("cls");
    user_face();
}

void user_face()
{
    printf("\t\tManager You Passwod\n");
    printf("----------------------------------------------------\n");
    printf("\t    welcome to password manager!\n");
    printf("\n");
    printf("Make your chioce:(0~2):\n");
    printf("1 :\tSave Your Password!\n");
    printf("2 :\tFind Your Password!\n");
    printf("3 :\tUpdate Your Password\n");
    printf("0 :\tGood-Bye!\n");
    printf("\n");
    printf("----------------------------------------------------\n");
}

void print_all()
{
    /*int i;
   for(i = 0;i<count;i++)
    {
        printf("username ");
        printf("password ");
        printf("Remark\n");

       printf("%s\t",acct_node[i].user_name);
        printf("%s\t",acct_node[i].pass_word);
        printf("%s\n",acct_node[i].remark);
    }*/

    Sleep(2000);
    system("cls");
    user_face();
}
