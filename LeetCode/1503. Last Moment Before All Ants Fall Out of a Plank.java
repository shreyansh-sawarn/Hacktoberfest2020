class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int max=0;
        for(int l:left)
            max=Math.max(max,l);
        for(int r:right)
            max=Math.max(max,n-r);
        return max;
    }
}