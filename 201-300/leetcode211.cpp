
typedef struct {
    unsigned int cnt;
    struct wordDictionary *next[26];    
} WordDictionary;

/** Initialize your data structure here. */
WordDictionary* wordDictionaryCreate() {
    WordDictionary *root = (WordDictionary *)malloc(sizeof(WordDictionary));
    memset(root, 0, sizeof(WordDictionary));
    return root;   
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    WordDictionary *node = obj;
    for (int i = 0; i < strlen(word); i++) {
        char c = word[i];
        if (node->next[c - 'a'] == NULL) {
            node->next[c - 'a'] = wordDictionaryCreate();
        }
        node = node->next[c - 'a'];
    }
    node->cnt++; // 表示以该node块挂接在的上一级位置对应的字符为结尾的单词的个数

    return;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
    WordDictionary *node = obj;

    for (int i = 0; i < strlen(word); i++) {
        char c = word[i];
        if (c == '.') {
            char j;
            for (j = 'a'; j <= 'z'; j++) {
                if (node->next[j - 'a'] == NULL) {
                    continue;
                }
                
                if (wordDictionarySearch(node->next[j - 'a'], word + i + 1)) {
                    return true;
                }
            }

            // 走到这里，说明上面for循环没有匹配到目标元素，单词查找失败
            return false;
        } else {
            if (node->next[c - 'a'] == NULL) {
                return false;
            }
            node = node->next[c - 'a'];
        }
    }

    return node->cnt != 0; // 如果node->cnt 不等于0，说明dictionary里有该word
}

void wordDictionaryFree(WordDictionary* obj) {
    if (obj == NULL) {
        return ;
    }
    
    for (int i = 0; i < 26; i++) {
        if (obj->next[i] != NULL) {
            wordDictionaryFree(obj->next[i]);
        }
    }
    free(obj);  
}