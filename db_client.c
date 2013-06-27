#include "db_client.h"

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
    //printf("共%d个字段\n",n_col);
    printf("字段名 : 字段值\n");
    for(i=0;i<n_col;i++)
    {
        //decode_pass_word();
        //printf("%s : %s\n",col_name[i],col_value[i]);
        printf("%s\t",col_value[i]);
    }
    printf("\n");
    return 0;
}
