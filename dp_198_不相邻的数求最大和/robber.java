class Solution {
    public int rob(int[] nums) {
        int length=nums.length;
        if(nums==null ||length==0)
        	return 0;
        else if(length==1)
        	return nums[0];
        else
        {
        	int[] f=new int[length];
        	f[0]=nums[0];
        	f[1]=Math.max(f[0],nums[1]);
        	for(int i=2;i<length;i++)
        	{
        		f[i]=Math.max(f[i-1],f[i-2]+nums[i]);
        	}
        	return f[length-1];
        }
    }
}