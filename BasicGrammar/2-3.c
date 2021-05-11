#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>


int htoi(char s[]);

int main() {

	char s[10];

	while(1) {
		scanf("%s", s);

		int num = htoi(s);

		printf("%d\n", num);
    }   
}

int htoi(char s[]) {
	int i, len, num, exp;

	num = 0;
	exp = 0;
	len = strlen(s);

	for(i = len -1; i >= 0; i--) {
		if(s[i] == 'x' || s[i] == 'X' && s[i-1] == '0')
			return num;

		if(isdigit(s[i])) {
			num += (s[i] - '0') * pow(16, exp);
		} else {
			num += (tolower(s[i]) - 65) * pow(16, exp);
		}

		exp++;
	}
}
