int hIndex(int* citations, int citationsSize){
int l=0,r=citationsSize;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(citations[citationsSize-mid]>=mid)
            l=mid;
        else r=mid-1;
    }
    return l;
}
