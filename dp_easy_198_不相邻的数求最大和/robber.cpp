int rob(vector<int> &nums)
{
	int size=nums.size();
	if(size==0)
	{
		return NULL;
	}
	else if(size==1)
	{
		return nums[0];
	}
	else
	{
		nums[1]=max(nums[0],nums[1]);
		for(int i=2;i<size;i++)
		{
			nums[i]=max(nums[i-1],nums[i-2]+nums[i]);
		}
		return nums[size-1];

	}
}