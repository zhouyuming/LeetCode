
struct TrieTree {
    struct TrieTree *link[26];
    int isEnd;
}

struct TrieTree *dict = NULL;
int idx = 0;

struct TrieTree buff[100000];

void initTree()
{
    idx = 0;
    dict = &buff[idx++];
    memset(dict->link, 0, sizeof(struct TrieTree*) * 26);
    dict->isEnd = 0;
    return;
}

void insertWord(struct TrieTree *dict, char *word)
{
    int len = strlen(word);
    int offset;
    struct TrieTree *tmp = dict;
    for (int i = 0; i < len; i++) {
        offset = word[i] - 'a';
        if (tmp->link[offset] == NULL) {
            tmp->link[offset] = &buff[idx++];
            memset(tmp->link[offset]->link, 0, sizeof(struct TrieTree*) * 26);
            tmp->link[offset]->isEnd = 0;
        }
        tmp = tmp->link[offset]; 
    }
    tmp->isEnd = 1;
    return;
}

char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize){
    initTree();
    for (int i = 0; i < wordsSize; i++) {
        insertWord(dict, words[i]);
    }
}