bool isMonotonic(int* A, int ASize){
    int flag= 0;

    for (int i = 0; i < ASize - 1; i++) {
        if (flag == -1 && A[i] < A[i + 1]) {
            return false;
        } else if (flag == 1 && A[i] > A[i + 1]) {
            return false;
        } else if (A[i] < A[i + 1]) {
            flag = 1;
        } else if (A[i] > A[i + 1]) {
            flag = -1;
        }
    }
    return true;
}