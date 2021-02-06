#include <gtest/gtest.h>

typedef struct tag_arr{
   int value;
   int pos; 
}arr;

int compare (const void * a, const void * b)
{
    if((* (arr * )a).value != ( * (arr * )b).value)
       return ( * (arr * )a).value > ( * (arr * )b).value ? 1 : -1;
    else return (* (arr * )a).pos -( * (arr * )b).pos;

}



bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    arr *tmp;
    tmp = (arr *)malloc(sizeof(arr)*numsSize);
    for(int i=0;i<numsSize;i++)
    {
        tmp[i].value = nums[i];
        tmp[i].pos = i;
    }
    qsort(tmp,numsSize,sizeof(arr),compare);
    for(int i=0;i<numsSize-1;i++)
    {
        if(tmp[i].value!=tmp[i+1].value)
            continue;
        else
        {
            int index = tmp[i+1].pos - tmp[i].pos;
            if(index <= k)
                return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num219x001)
{

}