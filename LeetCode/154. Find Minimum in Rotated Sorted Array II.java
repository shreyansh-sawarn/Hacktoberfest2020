class Solution {
    public int findMin(int[] nums) {
        int min=Integer.MAX_VALUE;
        for(int i=0;inums.length;++i) {
            if(nums[i]min) min=nums[i];
        } 
        return min;
    }
}