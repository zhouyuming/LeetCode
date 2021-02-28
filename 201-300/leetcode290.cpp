bool equals(char* s1, char* s2);

bool wordPattern(char * pattern, char * str){
    char* dictionary[26];
    for(int i = 0; i < 26; i++) { dictionary[i] = NULL; }
    while(*pattern != '\0') {
        if(*str == '\0') { return false; }
        if(dictionary[*pattern - 'a'] == NULL) {    // Pattern first appear
            dictionary[*pattern - 'a'] = str;
            for(int i = 0; i < 26; i++) {
                if(i != *pattern - 'a' && equals(dictionary[i], str)) { return false; }
            }
        }
        else {      // Pattern appeared befor
            if(!equals(dictionary[*pattern - 'a'], str)) { return false; }
        }
        pattern++;
        while(*str != ' ' && *str != '\0') { str++; }
        if(*str == ' ') { str++; }
    }
    return *str == '\0';
}

bool equals(char* s1, char* s2) {
    if(s1 == NULL && s2 == NULL) { return true; }
    if(s1 == NULL || s2 == NULL) { return false; }
    while(*s1 != ' ' && *s1 != '\0' && *s2 != ' ' && *s2 != '\0') {
        if(*s1 != *s2) { return false; }
        s1++, s2++;
    }
    if(*s1 != ' ' && *s1 != '\0') { return false; }
    if(*s2 != ' ' && *s2 != '\0') { return false; }
    return true;
}