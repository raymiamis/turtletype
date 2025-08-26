#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* words[] = {
    "the", "be", "and", "of", "a",
    "in", "to", "have", "to", "it",
    "that", "for", "you", "he", "with",
    "on", "do", "say", "this", "they",
    "at", "but", "we", "his", "from",
    "that", "by", "she", "or", "as"
};

int main() {

    printf("Timer will start as soon as the words are displayed.\nYour 10 words are:\n");

    int correctWords = 0;
    int indices[30];
    srand(time(NULL));  // setting seed for rand()

        // shuffling the indices of the word table
    for (int i = 0; i < 30; i++) indices[i] = i;
    for (int i = 29; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = indices[i];
        indices[i] = indices[j];
        indices[j] = tmp;
    }

        // printing the words
    for (int i = 0; i < 10; i++) {
        printf("%s ", words[indices[i]]);
    }
    printf("\n");

        // timer start
    time_t start = time(NULL);

        // getting user input
    char input[256];
    if (fgets(input, sizeof(input), stdin)) {

            // timer end and calculating diff
        time_t end = time(NULL);
        int timediff = difftime(end, start);

            // deleting the newline char from the input buffer
        input[strcspn(input, "\n")];

            // tokenizing the user input
        char* pToken = strtok(input, " ");

        int i;
        for (i = 0; i < 10 && pToken != NULL; i++) {

                // comparing with words
            if (strcmp(pToken, words[indices[i]])) {
                correctWords++;
            }

            strtok(NULL, " ");
        }

            // calculating wpm
        if (0 == timediff) timediff++;   // handling divide by zero error hehehe
        int wpm = (correctWords * 60) / timediff;

            // output summary
        if (i < 10) {
            printf("You typed less words than given. Separate your words by spaces.\n");
        } else {
            printf("Congrats! You typed %d correct words with a speed of %d WPM", correctWords, wpm);
        }

    } else {
        printf("Error while getting user input.");
    }    

    return 0;
}