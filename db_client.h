#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include "sqlite3.h"

//封装一下SQLITE3的SQL执行方法，统一SQL执行操作
void exec_sql(const char *sql,boolean is_query);

//查询时所用的回调函数，显示查询结果
int call_back(void *para ,int n_col,char **col_value,char **col_name);
