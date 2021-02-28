char * getHint(char * secret, char * guess){
    int s[10] = {0};
    int g[10] = {0};
    int m[10] = {0};

    for (int i = 0; i < strlen(secret); i++) {
        if (secret[i] == guess[i]) {
            s[secret[i] - '0']++;
            g[secret[i] - '0']++;
            m[secret[i] - '0']++;
        } else {
            s[secret[i] - '0']++;
            g[guess[i] - '0']++;    
        }
    } 
    char* res = (char*)malloc(100);
    int a = 0;
    int b = 0;
    for (int i = 0; i < 10; i++) {
        a += m[i];
        b += fmin(s[i], g[i]) - m[i];
    }
    sprintf(res, "%dA%dB", a, b);
    return res;
}