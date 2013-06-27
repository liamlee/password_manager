#include "passWordManager.h"

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

void save_pass_word()
{
    char insert_sql[SQL_LENGTH];
    char user_name[USER_SIZE];
    char pass_word[USER_SIZE];
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
    Sleep(SLEEP_TIME);
    //system("cls");
    //user_face();
}

void get_pass_word()
{
    //printf("Here you can find your password which you've forget!\n");
    char name[USER_SIZE];
    char query_sql[SQL_LENGTH];
    boolean is_query = TRUE;
    printf("Input your username:\n");
    gets(name);
    //code_user_name(name);

    sprintf(query_sql,"select * from account_info where user_name = '%s'",name);
    exec_sql(query_sql,is_query);
    //printf("%s\n",query_sql);

    Sleep(SLEEP_TIME);
    //system("cls");
    //user_face();
}

void update_pass_word()
{
    char update_sql[SQL_LENGTH];
    char user_name[USER_SIZE];
    char platform[USER_SIZE];
    char pass_word[USER_SIZE];
    char pass_word1[USER_SIZE];
    boolean is_query = FALSE;

    printf("user_name: ");
    gets(user_name);
    printf("platform: ");
    gets(platform);
    //code_user_name(user_name);
    printf("New password: ");
    gets(pass_word);
    printf("New password again: ");
    gets(pass_word1);
    //code_pass_word(pass_word);
    if(strcmp(pass_word,pass_word1) != 0)
    {
        printf("Not match!\n");
        Sleep(SLEEP_TIME);
        system("cls");
        return ;
    }

    sprintf(update_sql,"update account_info set pass_word = '%s' where user_name = '%s' and platform = '%s' ",pass_word,user_name,platform);
    //printf("%s\n",update_sql);

    exec_sql(update_sql,is_query);

    printf("Update successful!\n");
    Sleep(SLEEP_TIME);
    //system("cls");
    //user_face();
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
