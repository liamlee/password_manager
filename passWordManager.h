#include "db_client.h"
#include "encryption.h"

#define SQL_LENGTH 10240
#define USER_SIZE  20
#define SLEEP_TIME 3000

//�����������˻�������
void save_pass_word();

//�����û�����ѯ����
void get_pass_word();

//�����û������˺�����ƽ̨����������
void update_pass_word();

//�û�������ʾ����
void user_face();

//ʶ���û�����ѡ�񣬵�����Ӧģ��
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

