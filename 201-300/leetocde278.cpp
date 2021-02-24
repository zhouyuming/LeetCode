int firstBadVersion(int n) {
    //二分对半寻找减少API调用次数
    int left = 1;
    int right = n;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(isBadVersion(mid))//true为出错
        {
            right = mid-1;
        }    
        else
        {
            left=mid + 1; 
        }
    }
    return left;
}