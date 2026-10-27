#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define UPPER_RANGE_BOTTOM 65
#define UPPER_RANGE_TOP 90

#define HELLO_WORLD_LEN 12

#define VALID_COMB 4

#ifdef _WIN32
	#define CLEAR_CMD "cls"
#else
	#define CLEAR_CMD "clear"
#endif

void lower(char **dst, const char *src);
size_t noBlanks(char **dst, const char *src);

int main() {
	const char *validCombinations[VALID_COMB] = {
		"hello,world",
		"hello,world!",
		"helloworld",
		"helloworld!",
	};

	char *line, *lineLowered, *noBlLine;
	line = lineLowered = noBlLine = nullptr;
	size_t maxSize = 1024;
	unsigned char validComb = 0;

	getline(&line, &maxSize, stdin);

	lower(&lineLowered, line);
	size_t lenOverflow = noBlanks(&noBlLine, lineLowered) != 0;

	for (size_t i = 0; !lenOverflow && i < VALID_COMB; ++i) {
		if (strncmp(noBlLine, validCombinations[i], HELLO_WORLD_LEN)) {
			validComb = 1;
			break;
		}
	}

	validComb &= !lenOverflow;

	system(CLEAR_CMD);
	printf("\033[38;5;8mTu programa es...\033[0m\n");
	sleep(1)

	free(line);
	free(noBlLine);
	free(lineLowered);

	return 0;
}

void lower(char **dst, const char *src) {
	char curr;
	size_t len = 0;

	*dst = (char *)malloc(sizeof(char) * len + 1); // Acount for the null terminator

	for (; (curr = src[len]) != '\0'; ++len) {
		if (curr >= UPPER_RANGE_BOTTOM && curr <= UPPER_RANGE_TOP) curr += 32;
		(*dst)[len] = curr;
	}

	(*dst)[len] = '\0';
}

size_t noBlanks(char **dst, const char *src) {
	const char *curr = src;
	size_t trimmedLen = 0, valid = 1;
	*dst = (char *)malloc(sizeof(char) * HELLO_WORLD_LEN + 1);

	while (*curr != '\0') {
		if (trimmedLen > HELLO_WORLD_LEN - 1) {
			valid = 0;
			break;
		}
		if (*curr != ' ') (*dst)[trimmedLen++] = *curr;
		curr++;
	}

	(*dst)[trimmedLen] = '\0';
	return valid;
}
