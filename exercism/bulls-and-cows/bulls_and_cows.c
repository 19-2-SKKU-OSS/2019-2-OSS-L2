
// This code is for playing bulls and cows
// In this code, 4 numbers are required
// redjo99 updated in 4.June.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 4

int PlayBullsAndCows(int arr[], int size) {
	int* guess = malloc(sizeof(int)*size);//make size of variable size "guess" array
	int strike = 0, ball = 0;
	for (int i = 0; i < size; i++) {
		scanf("%d", &guess[i]);//get input in "guess" array
		if (guess[i] == arr[i]) {
			strike++;//if index of both array are same, add +1 to strike variable
		}
		else {
			for (int j = 0; j < size; j++) {
				if (guess[i] == arr[j]) {// if index of both array are different, add +1 to ball variable
					ball++;
					break;
				}
			}
		}
	}
	free(guess);
	return strike * 10 + ball;//return value
}

void CreateRandomNumbers(int arr[], int size) {
	srand(time(NULL));//create Random Numbers for playing BullAndCows Game
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
		}
		printf("%d\n", arr[i]);
	}
}

int main(void) {
	int num[MAX];
	int strike, ball, point = 0;

	CreateRandomNumbers(num, MAX);

	printf("There are 4 random numbers(0~9).\nPlease input your guessing numbers in order!\n");
	
	while (point < MAX * 10) {
		point = PlayBullsAndCows(num, MAX);
		printf("%d strike and %d ball\n", point / 10, point % 10);
	}
	printf("\nCongratulations!");

	return 0;
}
