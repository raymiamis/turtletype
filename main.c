#include <stdio.h>
#include <string.h>

const char* words[] = {
    "the", "be", "and", "of", "a",
    "in", "to", "have", "to", "it",
    "that", "for", "you", "he", "with",
    "on", "do", "say", "this", "they",
    "at", "but", "we", "his", "from",
    "that", "by", "she", "or", "as"
};

int main() {

    int indices[30];
    for (int i = 0; i < 30; i++) indices[i] = i;


    for (int i = 29; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = indices[i];
        indices[i] = indices[j];
        indices[j] = tmp;
    }


    for (int i = 0; i < 10; i++) {
        printf("%s ", words[indices[i]]);
    }

    char input[256];
    if (fgets(input, sizeof(input), stdin)) {
        input[strcspn(input, "\n")];

        char* pToken = strtok(input, " ");

        int i;
        for (i = 0; i < 10 && pToken != NULL; i++) {
            // TODO: compare tokens to strings

            strtok(NULL, " ");
        }

        if (i < 10) {
            printf("You typed less words than given. Separate your words by spaces.\n");
        }
    }

    

    return 0;
}