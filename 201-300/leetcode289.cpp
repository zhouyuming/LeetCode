void update(int** board,int i,int j,int bS,int bCS){
    int sum=0;
    for(int m=i-1;m<=i+1;m++){
        if(m<0||m==bS)continue;
         for(int n=j-1;n<=j+1;n++){
             if(m==i&&n==j)continue;
             if(n<0||n==bCS)continue;
             sum+=board[m][n] & 1;
         }
     }
     if((board[i][j]&1)>0){
         if(sum>=2&&sum<=3)board[i][j]=0b11;
     }else if(sum==3)board[i][j]=0b10;
}
void gameOfLife(int** board, int boardSize, int* boardColSize){
     if(boardSize==0)return;
     for(int i=0;i<boardSize;i++){
         for(int j=0;j<boardColSize[0];j++){
             update(board,i,j,boardSize,boardColSize[0]);
         }
     }
     for(int i=0;i<boardSize;i++){
         for(int j=0;j<boardColSize[0];j++){
             board[i][j] >>= 1;
         }
     }
}
