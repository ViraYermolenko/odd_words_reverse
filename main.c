#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** allocateMemoryForWordsArray(int);
void fillWords (char**, int );
char swapWords (int, char**);
void freeMemory (int, char **);



int main() {

    char** words;
    int words_count;

    printf("Count of words >  ");
    scanf("%d",&words_count);

    words = allocateMemoryForWordsArray(words_count);

    printf("\nWords filling: \n\n");

    fillWords(words, words_count);

    int new_words_count = words_count / 2;
    char ** new_words;

    new_words = allocateMemoryForWordsArray(new_words_count);
    for(int i = 0; i < new_words_count; i++){
        strcpy(new_words[i],words[i*2 + 1]);
    }

    swapWords (new_words_count, new_words);

    printf("\nResult words list: ");
    for(int i = 0; i < new_words_count; i++){
        printf("%s ",new_words[i]);
    }
    printf("\n\n");

    freeMemory (words_count, words);
    freeMemory (new_words_count, new_words);

    return 0;
}


char **allocateMemoryForWordsArray(int words_count) {
    char ** words = (char**)malloc(sizeof(char*)*words_count);
    if (words == NULL){
        exit(1);
    }
    for(int i=0;i<words_count;i++)
        words[i] = (char*)malloc(sizeof(char)*255);

     return words;
}

void fillWords (char**  words, int words_count) {
    for (int i = 0; i < words_count; i++) {
        printf("%d > ", i + 1);
        scanf("%s", words[i]);
    }
    printf("\nWords list: ");
    for (int i = 0; i < words_count; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");
}

char swapWords (int new_words_count, char** new_words) {
    for (int i = 0; i < new_words_count; i++) {
        for (int j = 0; j < strlen(new_words[i]) / 2; j++) {
            char buffer = new_words[i][j];
            new_words[i][j] = new_words[i][strlen(new_words[i]) - j - 1];
            new_words[i][strlen(new_words[i]) - j - 1] = buffer;
        }
    }
    return 0;
}

void freeMemory (int n, char ** words) {
    for (int i = 0; i < n; i++)
        free(words[i]);
    free(words);
}