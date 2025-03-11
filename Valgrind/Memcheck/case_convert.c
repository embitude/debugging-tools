#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH (60)

char *convertStringToCaps(const char *srcString, char *dstString) {
	const char *csrc = srcString;
	char *cdst = malloc(strlen(srcString));
	char *retVal = cdst;
	while ((csrc != NULL) && (*csrc != '\0')) {
	*cdst = toupper(*csrc);
	cdst++;
	csrc++;
	}
	*cdst = '\0';
	return retVal;
}

char *convertStringToLowerCase(const char *srcString, char *dstString) {
	const char *csrc = srcString;
	//char *cdst = malloc(strlen(srcString));
	char *cdst = dstString;
	char *retVal = cdst;
	while ((csrc != NULL) && (*csrc != '\0')) {
	*cdst = tolower(*csrc);
	cdst++;
	csrc++;
	}
	*cdst = '\0';
	return retVal;
}

int main(int argc, char *argv[]) {
	char initialString[MAX_MSG_LENGTH];
	char *capsString = NULL;
	char *lcString = NULL;
	
	printf("Please enter the String\n");
	fgets(initialString, MAX_MSG_LENGTH, stdin);
	capsString = malloc(strlen(initialString) + 1);
	lcString = malloc(strlen(initialString) + 1);
	capsString = convertStringToCaps(initialString, capsString);
	lcString = convertStringToLowerCase(initialString, lcString);
	printf("Initial String = %s\n", initialString);
	printf("Caps String = %s\n", capsString);
	printf("Lower Case String = %s\n", lcString);
	free(lcString);

	return 0;
}
