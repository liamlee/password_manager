#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include "sqlite3.h"

//��װһ��SQLITE3��SQLִ�з�����ͳһSQLִ�в���
void exec_sql(const char *sql,boolean is_query);

//��ѯʱ���õĻص���������ʾ��ѯ���
int call_back(void *para ,int n_col,char **col_value,char **col_name);
