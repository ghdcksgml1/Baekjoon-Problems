#include <stdio.h>

int main(void) {
	int alphabet[26];
	char s[100];
	for (int i = 0; i < 26; i++)
		alphabet[i] = -1;
	
	scanf("%s", &s);
	for (int i = 0; s[i] != NULL; i++) {
		s[i] -= 'a';
		if (alphabet[((int)s[i])] != -1)
			continue;
		alphabet[((int)s[i])] = i;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}

	return 0;
}