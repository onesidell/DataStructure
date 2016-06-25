#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h> 


#define TEXT 30000 // 텍스트파일 크기
#define MAX 1000
char* ull;//strtoul을 위해 사용된 무의미한 변수
char string[100];

//user.txt 받기
typedef struct userlist {
	unsigned long user_number;
	char* user_id;
	long friendnum;
	long tweetnum;
};

//friend.txt 받기
typedef struct friendlist {
	unsigned long my_num;
	unsigned long friend_num;
};

//word.txt 받기
typedef struct	wordtweetlist {
	unsigned long user_id2;
	char* tweetword;
};
//txt 받아서 입력
void userlist_init(userlist* self) {
	self->user_number = 0;
	self->user_id = (char*)malloc(sizeof(char)*MAX);
	self->friendnum = 0;
	self->tweetnum = 0;
}
void friendlist_init(friendlist* self) {
	self->my_num = 0;
	self->friend_num = 0;
}
void wordtweetlist_init(wordtweetlist* self) {
	self->user_id2 = 0;
	self->tweetword = (char*)malloc(sizeof(char)*MAX);;
}




















void Interface()
{
	puts("0. Read data files");
	puts("1. display statistics");
	puts("2. Top 5 most tweeted words");
	puts("3. Top 5 most tweeted users");
	puts("4. Find users who tweeted a word (e.g., ’연세대’)");
	puts("5. Find all people who are friends of the above users");
	puts("6. Delete all mentions of a word");
	puts("7. Delete all users who mentioned a word");
	puts("8. Find strongly connected components");
	puts("9. Find shortest path from a given user");
	puts("99. Quit");
	printf("Select Menu: ");
}

int main() {
	char* size1 = (char*)malloc(sizeof(char)*MAX);
	char* size2 = (char*)malloc(sizeof(char)*MAX);
	char* date = (char*)malloc(sizeof(char)*MAX);
	char* name = (char*)malloc(sizeof(char)*MAX);
	char* tweet = (char*)malloc(sizeof(char)*MAX);
	char* empty = (char*)malloc(sizeof(char)*MAX);

	userlist users[TEXT];
	friendlist friends[TEXT];
	wordtweetlist words[TEXT];

	FILE* User;
	FILE* Friend;
	FILE* Word;

	User = fopen("user.txt", "r");
	Friend = fopen("friend.txt", "r");
	Word = fopen("word.txt", "r");

	long TotalUser = 0;				//전체 유저 수
	long TotalFriend = 0;			//전체 친구 수
	long TotalTweetword = 0;		//전체 트윗 수
	long AvgF = 0;					//평균 친구 수
	long MinF = 0;					//최소 친구 수
	long MaxF = 0;					//최대 친구 수
	long AvgT = 0;					//평균 트윗 수
	long MinT = 0;					//최소 트윗 수
	long MaxT = 0;					//최대 트윗 수
	
	//user.txt
	while ((!feof(User)) && (TotalUser < TEXT)) {
		int i = 0;
		fgets(size1, MAX, User);					//user_id
		fgets(date, MAX, User);						//날짜
		fgets(name, MAX, User);						//이름
		fgets(empty, MAX, User);					//emptystring

		userlist_init(&users[TotalUser]);
		users[TotalUser].user_number = strtoul(size1, &ull, 10);
		strcpy(users[TotalUser].user_id, name);
		users[TotalUser].friendnum = 0;
		TotalUser++;
		i++;
	}
	//friend.txt
	while ((!feof(Friend)) && (TotalFriend < TEXT)) {
		fgets(size1, MAX, Friend);		//my_num
		fgets(size2, MAX, Friend);		//friend_num
		fgets(empty, MAX, Friend);		//emptystring 
		for (int i = 0; i < TotalUser; i++) {
			if (users[i].user_number == strtoull(size2, &ull, 10)) {
				users[i].friendnum++;
				friendlist_init(&friends[TotalFriend]);
				friends[TotalFriend].my_num = strtoull(size1, &ull, 10);
				friends[TotalFriend].friend_num = strtoull(size2, &ull, 10);
				TotalFriend++;
				break;
			}
		}
	}
	//word.txt
	while ((!feof(Word)) && (TotalTweetword < TEXT)) {
		fgets(size1, MAX, Word);				//user_id2
		fgets(date, MAX, Word);					//날짜
		fgets(tweet, MAX, Word);				//tweetword
		fgets(empty, MAX, Word);				//emptystring

		wordtweetlist_init(&words[TotalTweetword]);
		words[TotalTweetword].user_id2 = strtoull(size1, &ull, 10);
		strcpy(words[TotalTweetword].tweetword, tweet);

		TotalTweetword++;

		for (int i = 0; i < TotalUser; i++) {//유저별 트윗 횟수 더하기
			if (users[i].user_number == strtoull(size1, &ull, 10)) {
				users[i].tweetnum += 1;
				break;
			}
		}
		AvgT = TotalTweetword / TotalUser;
		AvgF = TotalFriend / TotalUser;
	}

	fclose(Friend);
	fclose(User);
	fclose(Word);

	while (1) {
		Interface();

		//menu select
		int select;
		scanf("%d", &select);
		
		if (select == 0) {
			printf("\nTotal users: %d\n", TotalUser);
			printf("Total friendship records: %d\n", TotalFriend);
			printf("Total tweets: %d\n\n", TotalTweetword);
		}
		if (select == 1) {
			MaxF = 0;
			MinF = AvgF;
			for (int i = 0; i < TotalUser; i++) {
				if (MaxF < users[i].friendnum) {
					MaxF = users[i].friendnum;
				}
				if (MinF > users[i].friendnum) {
					MinF = users[i].friendnum;
				}
			}

			printf("\nAverage number of friends : %d\n", AvgF);
			printf("Minimum number of friends : %d\n", MinF);
			printf("Maximum number of friends : %d\n\n", MaxF);


			for (int i = 0; i < TotalUser; i++) {
				if (MaxT < users[i].tweetnum) {
					MaxT = users[i].tweetnum;
				}
				if (MinT > users[i].tweetnum) {
					MinT = users[i].tweetnum;
				}
			}

			printf("Average tweets per user : %d\n", AvgT);
			printf("Minimum tweets per user : %d\n", MinT);
			printf("Maximum tweets per user : %d\n\n", MaxT);

		}
		if (select == 2) {
		}
		if (select == 3) {
		}
		if (select == 4) {
			int check = 0;
			int k = 0;
			printf("\nSearch a word : ");
			scanf("%s", string);
			strcat(string, "\n");

			while (k < TotalTweetword) {
				if (strcmp(words[k].tweetword, string) == 0) {
					printf("\n%lu tweeted\n", words[k].user_id2);
					check = true;
				}
				k++;
			}
			printf("\n");
			if (!check)
				printf("\nNo tweeted word\n\n");
		}
		if (select == 5) {
			int check = 0;
			int k = 0;
			printf("Search word : %s \n", string);
			while (k < TotalTweetword)
			{
				if (strcmp(words[k].tweetword, string) == 0)
				{
					printf("ID NUM: %d  \n", words[k].user_id2);
					printf("Friends List: ");
					
					for (int i = 0; i < TotalFriend; i++)
					{
						if (words[k].user_id2 == friends[i].my_num)
							printf("%d / ", friends[i].friend_num);
						else if (words[k].user_id2 == friends[i].friend_num)
							printf("%d / ", friends[i].my_num);
					}
					printf("\n");
				}
				k++;
				check = 1;
			}
			if (!check)
				printf("%s does not exit in text file\n", string);
			printf("\n");
		}
		if (select == 6) {
			int i = 0;
			printf("Searched word : %s", string);
			printf("Delete all mentions of the word\n");
			while (i < TotalTweetword) {
				if (strcmp(words[i].tweetword, string) == 0) {
					words[i].tweetword = "";
					TotalTweetword--;                                      //트윗 삭제
				}
				i++;
			}printf("\n");
		}
		if (select == 7) {
			int i = 0;
			int tmp;
			printf("Searched word : %s", string);
			printf("Delete all users who mentioned the word\n");
			while (i < TotalTweetword) {
				if (strcmp(words[i].tweetword, "") == 0) {
					tmp = words[i].user_id2;
					for (int j = 0; j < TotalTweetword; j++)
					{
						if (words[j].user_id2 == tmp) {
							words[j].user_id2 = '\n';
							TotalTweetword--;                                //동일유저의 모든 트윗삭제
						}						
					}
					TotalUser--;
				}
				i++;
			}printf("\n");
		}
		if (select == 8) {
		}
		if (select == 9) {
		}
		if (select == 99) {
			break;
		}
	}
	
	return 0;
}
