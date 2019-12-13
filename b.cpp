//In The Name Of GOD
#include<stdio.h>

int check();

char c[3][3];
int v, flag;

int main() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] = i * 10 + j;
	while (!check()) {
		if (flag != 1) { // player x
			printf("Player X:\n");
			scanf("%d", &v);
			if (v < 4)
				c[0][v - 1] = 'X';
			else if (v < 7)
				c[1][v - 4] = 'X';
			else
				c[2][v - 7] = 'X';
		}
		else {
			printf("Player O:\n");
			scanf("%d", &v);
			if (v < 4)
				c[0][v - 1] = 'O';
			else if (v < 7)
				c[1][v - 4] = 'O';
			else
				c[2][v - 7] = 'O';
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				if (c[i][j] == 'X' || c[i][j] == 'O') {
					if (j == 0) 
						printf("%c |", c[i][j]);
					else if (j == 1)
						printf(" %c |", c[i][j]);
					else 
						printf(" %c\n", c[i][j]);
				}
				else {
					if (j == 0)
						printf("  |");
					else if (j == 1)
						printf("   |");
					else
						printf("\n");
				}
			printf("\n");
		}
		flag = 1 - flag;
	}
	printf("The Winner Is ");
	if (flag != 1)
		printf("Player O\n");
	else
		printf("Player X\n");
	return 0;
}

int check() {
	for (int i = 0; i < 3; i++)
		if (c[i][0] == c[i][1] && c[i][0] == c[i][2])
			return 1;
		else if (c[0][i] == c[1][i] && c[0][i] == c[2][i])
			return true;
	if (c[0][0] == c[1][1] && c[0][0] == c[2][2])
		return 1;
	if (c[0][2] == c[1][1] && c[2][0] == c[1][1])
		return 1;
	return 0;
}