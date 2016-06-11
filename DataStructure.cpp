#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h> //strtoul 사용

#define TEXT 10000 // 텍스트파일 크기
#define MAX 1000

//user.txt 받기
typedef struct userlist {
	unsigned long user_number;
	char* user_id;
	long friendnum;
	long tweetnum;
} userlist;

//friend.txt 받기
typedef struct friendlist {
	unsigned long my_number;
	unsigned long friend_number;
} friendlist;

//word.txt 받기
typedef struct	wordtweetlist {
	unsigned long user_id2;
	char* tweetword;
} wordtweetlist;

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

	Friend = fopen("friend.txt", "r");
	User = fopen("user.txt", "r");
	Word = fopen("word.txt", "r");
	
	long TotalUser = 0;
	long TotalFriend = 0;
	long TotalTweetword = 0;
	
	//user.txt
	while ((!feof(User)) && (TotalUser < TEXT)) {
		fgets(size1, MAX, User);					//user_id
		fgets(date, MAX, User);						//날짜
		fgets(name, MAX, User);						//이름
		fgets(empty, MAX, User);					//emptystring 
	}
	//friend.txt
	while ((!feof(Friend)) && (TotalFriend < TEXT)) {
		fgets(size1, MAX, Friend);						//my_number
		fgets(size2, MAX, Friend);						//friend_number
		fgets(empty, MAX, Friend);						//emptystring 
	}
	//word.txt
	while ((!feof(Word)) && (TotalTweetword < TEXT)) {
		fgets(size1, MAX, Word);				//user_id2
		fgets(date, MAX, Word);					//날짜 
		fgets(tweet, MAX, Word);				//tweetword
		fgets(empty, MAX, Word);				//emptystring
	}
	fclose(Friend);
	fclose(User);
	fclose(Word);
	
	while (1) {
		int interface = 0;

		printf("0. Read data files\n");
		printf("1. display statistics\n");
		printf("2. Top 5 most tweeted words\n");
		printf("3. Top 5 most tweeted users\n");
		printf("4. Find users who tweeted a word\n");
		printf("5. Find all people who are friends of the above users\n");
		printf("6. Delete all mentions of a word\n");
		printf("7. Delete all users who mentioned a word\n");
		printf("8. Find strongly connected components\n");
		printf("9. Find shortest path from a given user\n");
		printf("99. Quit\n");
		printf("Select Menu : ");
		//interface
		scanf("%d", &interface);

		if (interface == 0) {

		}
		if (interface == 1) {

		}
		if (interface == 2) {

		}
		if (interface == 3) {

		}
		if (interface == 4) {

		}
		if (interface == 5) {

		}
		if (interface == 6) {

		}
		if (interface == 7) {

		}
		if (interface == 8) {

		}
		if (interface == 9) {

		}
		if (interface == 99) {
		}
	}
	return 0;
}
