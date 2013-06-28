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
        case '4':
            remove_account();
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
    char platform[USER_SIZE];
    char remark[50];
    int result;
    boolean is_query = FALSE;

    printf("Input your username:\n>");
    gets(user_name);
    //code_user_name(user_name);

    printf("Input your password:\n>");
    gets(pass_word);
    //code_pass_word(pass_word);
    printf("Input the platform for this account:\n>");
    gets(platform);

    printf("Remark the account!:\n>");
    gets(remark);

    /*printf("username %s ",user_name);
    printf("password %s ",pass_word);
    printf("Remark %s\n ",remark);*/

    sprintf(insert_sql,"insert into account_info values('%s','%s','%s','%s')",user_name,pass_word,platform,remark);
    //printf("%s\n",insert_sql);

    result = exec_sql(insert_sql,is_query);
    if(result)
    {
        Sleep(SLEEP_TIME);
        return ;
    }

    printf("Save successful!\n");
    Sleep(SLEEP_TIME);
}

void get_pass_word()
{
    //printf("Here you can find your password which you've forget!\n");
    char name[USER_SIZE];
    char query_sql[SQL_LENGTH];

    boolean is_query = TRUE;
    printf("Input your username:\n>");
    gets(name);
    //code_user_name(name);

    sprintf(query_sql,"select * from account_info where user_name = '%s'",name);
    exec_sql(query_sql,is_query);
    //printf("%s\n",query_sql);

    Sleep(SLEEP_TIME);
}

void update_pass_word()
{
    char update_sql[SQL_LENGTH];
    char user_name[USER_SIZE];
    char platform[USER_SIZE];
    char pass_word[USER_SIZE];
    char pass_word1[USER_SIZE];
    int result ;
    boolean is_query = FALSE;

    printf("user_name:\n>");
    gets(user_name);
    printf("platform:\n>");
    gets(platform);
    //code_user_name(user_name);
    printf("New password:\n>");
    gets(pass_word);
    printf("New password again:\n>");
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

    result = exec_sql(update_sql,is_query);
    if(result)
    {
        Sleep(SLEEP_TIME);
        return ;
    }

    printf("Update successful!\n");
    Sleep(SLEEP_TIME);
}

void remove_account()
{
    char delete_sql[SQL_LENGTH];
    char user_name[USER_SIZE];
    char Y_N;
    char platform[USER_SIZE];

    int result ;
    boolean is_query = FALSE;

    printf("user_name:\n>");
    gets(user_name);
    printf("platform:\n>");
    gets(platform);

    printf("Are you sure to remove this account? (Y/N)\n>");
    scanf("%c",&Y_N);
    getchar();
    if('Y' != Y_N)
    {
        printf("Your have cancel this remove action!");
        Sleep(SLEEP_TIME);
        return ;
    }

    sprintf(delete_sql,"delete from  account_info where user_name = '%s' and platform = '%s' ",user_name,platform);

    result = exec_sql(delete_sql,is_query);
    if(result)
    {
        Sleep(SLEEP_TIME);
        return ;
    }

    printf("Delete successful!\n");
    Sleep(SLEEP_TIME);

}

void user_face()
{
    printf("\t\tManager You Passwod\n");
    printf("----------------------------------------------------\n");
    printf("\t    welcome to password manager!\n");
    printf("\n");
    printf("\t1 :\tSave Your Password!\n");
    printf("\t2 :\tFind Your Password!\n");
    printf("\t3 :\tUpdate Your Password!\n");
    printf("\t4 :\tRemove Your Account!\n");
    printf("\t0 :\tGood-Bye!\n");
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("Make your chioce:(0~4):\n");
    printf(">");
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
