
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

    return 0;
}