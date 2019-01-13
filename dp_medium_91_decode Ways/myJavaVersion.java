class Solution {
    public int numDecodings(String s) {
        int length=s.length();
        if(length==0||s.charAt(0)=='0'){
            return 0;
        }
        if(length==1)
        {
            return 1;
        }
        int[] dp=new int[length+1];
        dp[0]=1;
        dp[1]=s.charAt(1)!='0'?1:0;
        for(int i=2;i<length;i++)
        {
            if (s.charAt(i) == '0') 
                continue;
            else{
                dp[i]=(Integer.parseInt(s.substring(i-2,i))>26)?dp[i-1]:dp[i-1]+dp[i-2];
            }
        }
        dp[length]=(Integer.parseInt(s.substring(length-2,length))>26)?dp[length-1]:dp[length-1]+dp[length-2];
        return dp[length];
    }
}