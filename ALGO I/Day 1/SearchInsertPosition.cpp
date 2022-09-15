

int searchInsert(int* nums, int numsSize, int target){
    int tempIndex=0;
   for(int i=0;i<numsSize;i++){
       if(nums[i]==target){
           return i;
           break;
       }
       else if(nums[i]<target){
           tempIndex++;
       }
   }
    return tempIndex;
}