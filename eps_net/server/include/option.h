#define files_name "data/select.db"
#define option_name "data/option.ini"
#define user_name "data/user.db"

#define MAX_TEXT 1000
#define MAX_SUM 10000
#define MAX_USER 100

#define SERVPORT 1707 /*server port num */
#define BACKLOG 100 /*max link*/


typedef struct data
{
	char text[MAX_TEXT];
	char ans;
}DATA;

typedef struct user
{
	int user_id;
	int passwd;
	int num;
	char answer[MAX_SUM];
}USER;

void clear_type();
void work_place(char* str);
int read_data();
void start_pg(char* argv[],DATA* head_data,int data_sum,USER* head_user,int user_sum);
int rw_option( char rw , int nb , int n );
