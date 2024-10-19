#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

char con;
int ans;

static void *
child(void *tpp){
	
	int* num = (int*) tpp;
	int num1 = *num;
	num++;
	int num2 = *num;
	switch(con){
		case '+':
			ans = num1 + num2;
			break;
                case '-':
			ans = num1 - num2;
                        break;
                case '*':
			ans = num1 * num2;
                        break;
                case '/':
			ans = num1 / num2;
                        break;
		default:
			printf("That isn't a valid case bum");
	}

	return NULL;
}

int
main(int argc, char *argv[]){

	pthread_t child_thread;
	int* temp = (int*)malloc(2 * sizeof(int));
	int* temper = temp;
	int i, scan, code;
	FILE *fptr = fopen("test.txt", "w");
	char str[50] = "Here's ur thingys";
	fprintf(fptr, "%s\n", str);
	if (fptr == NULL){
		printf("nuh");
	}
	for (i = 0; i < 2; i++){
		printf("Gimme Number ");
		scanf(" %d", &scan);
		*temp = scan;
		temp++;
	}
	temp = temper;

	printf("What're tryin to do with these 2 numbers? + - / or * ");
	scanf(" %c", &con);

	code = pthread_create(&child_thread, NULL, child, temp);
	if (code){
		fprintf(stderr, "pthread_create failed with code %d\n", code);
	}
	sleep(1);
	fprintf(fptr, "%d", ans);
	fclose(fptr);
	FILE *fptr2 = fopen("test.txt", "r");
	char t[50];
	char t2[50];
	int ti;
	fgets(t, 50, fptr2);
	fgets(t2, 50, fptr2);
	ti = atoi(t2);
	printf("%s%d\n", t, ti);
	fclose(fptr2);
	return 0;
}
