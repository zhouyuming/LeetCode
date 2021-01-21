
struct TrieTree {
    struct TrieTree *link[26];
    int isEnd;
};

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

struct StackNode {
    int top;
    char *data;
    int size;
};

struct StackNode *initStack(int size)
{
    struct StackNode *s = malloc(sizeof(struct StackNode));
    s->top = -1;
    s->data = malloc(sizeof(char) * size);
    memset(s->data, 0, sizeof(char) * size);
    s->size = size;
    return s;
}

void push(struct StackNode *s, char c)
{
    s->data[++s->top] = c;
}

char pop(struct StackNode *s)
{
    return s->data[s->top--];
}

void recordResult(struct StackNode *s, char **res, int *retSz)
{
    int len = s->top + 1;
    char *word = malloc(sizeof(char) * (len + 1));
    memcpy(word, s->data, sizeof(char) * len);
    word[len] = '\0';
    for (int i = 0; i < *retSz; i++) {
        if (strcmp(word, res[i]) == 0) {
            return;
        }
    }
    res[(*retSz)] = word;
    (*retSz)++;
}

void dfs(char **board, int rowSz, int colSz, char **res, int *retSz, char **mask, int i, int j, struct TrieTree *d, struct StackNode *s)
{
    if (i < 0 || i == rowSz || j < 0 || j == colSz) {
        return;
    }

    if (d == NULL) {
        return NULL;
    }

    if (mask[i][j] == 1) {
        return;
    }

    int offset = board[i][j] - 'a';
    if (d->link[offset] == NULL) {
        return;
    }
    d = d->link[offset];
    push(s, board[i][j]);
    mask[i][j] = 1;

    if (d->isEnd == 1) {
        recordResult(s, res, retSz);
    }
    dfs(board, rowSz, colSz, res, retSz, mask, i + 1, j, d, s);
    dfs(board, rowSz, colSz, res, retSz, mask, i - 1, j, d, s);
    dfs(board, rowSz, colSz, res, retSz, mask, i, j + 1, d, s);
    dfs(board, rowSz, colSz, res, retSz, mask, i, j - 1, d, s);
    mask[i][j] = 0;
    pop(s);
    return;
}

char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize){
    initTree();
    for (int i = 0; i < wordsSize; i++) {
        insertWord(dict, words[i]);
    }

    char **res = (char**)malloc(sizeof(char*) * 1000);
    *returnSize = 0;

    char **mask = (char**)malloc(sizeof(char*) * boardSize);
    for (int i = 0; i < boardSize; i++) {
        mask[i] = (char*)malloc(sizeof(char) * (*boardColSize));
        memset(mask[i], 0, sizeof(char) * (*boardColSize));
    }

    struct StackNode * s = initStack(1000);

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            dfs(board, boardSize, *boardColSize, res, returnSize, mask, i, j, dict, s);
        }
    }
    return res;
}