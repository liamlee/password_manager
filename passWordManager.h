#include "db_client.h"
#include "encryption.h"

#define SQL_LENGTH 10240
#define USER_SIZE  20
#define SLEEP_TIME 3000

//保存新增的账户、密码
void save_pass_word();

//根据用户名查询密码
void get_pass_word();

//根据用户名、账号所在平台，更新密码
void update_pass_word();

//用户操作提示界面
void user_face();

//识别用户操作选择，调用相应模块
void deal_chioce();


void print_all();


/*typedef struct account
{
    char user_name[20];
    char pass_word[20];
    char remark[50];
}NODE;
*/
//int count = 0;
//NODE acct_node[100];

