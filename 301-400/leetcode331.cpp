bool isValidSerialization(char * preorder){
    int len = strlen(preorder);
    int numcnt = 0;
    int jincnt = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (preorder[i] == '#') {
            jincnt++;
        } else if (preorder[i] == ',') {
            continue;
        } else {
            while (i >= 0 && preorder[i] != '#' && preorder[i] != ',') {
                i--;
            }
            i++;
            numcnt++;
        }
        if (numcnt == 1 && jincnt >= 2) {
            numcnt = 0;
            jincnt -= 1;
        } else if (numcnt >= 1) {
            return false;
        }
    }
    return numcnt == 0 && jincnt == 1;
}