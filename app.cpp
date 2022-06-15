int maxProfit(vector<int> prices, int buy, int index, int cap)
{
    if(index == prices.size())
        return 0;
    if(cap == 0)
        return 0;
    int profit = 0;
    if(buy)
    {
        int buying = -prices[index] + maxProfit(prices,0,index+1,cap);
        int not_buying = maxProfit(prices,1,index+1,cap);
        profit = max(buying,not_buying);
    }
    else
    {
        int sell = prices[index] + maxProfit(prices,1,index+2,cap-1);
        int not_sell = maxProfit(prices,0,index+1,cap);
        profit = max(sell,not_sell);
    }
    return profit;
}

int maxProfit(vector<int>& prices, int buy, int i, int cap)
{
    if(i == prices.size())
        return 0;
    if(cap == 0)
        return 0;
    if(dp[i][buy][cap] != -1)
    {
        return dp[i][buy][cap];
    }
    if(buy)
    {
        int buying = -prices[index] + maxProfit(prices,0,index+1,cap);
        int not_buying = maxProfit(prices,1,index+1,cap);
        profit = max(buying,not_buying);
    }
    else
    {
        int sell = prices[index] + maxProfit(prices,1,index+1,cap-1);
        int not_sell = maxProfit(prices,0,index+1,cap);
        profit = max(sell,not_sell);
    }
    return dp[i][buy][cap] = profit;
}

int maxProfit(vector<int>& prices)
{
    int dp[n+1][2][3];
    dp[n][0][0] = dp[n][1][0] = 0;
    for(int i = n-1 ; i >= 0 ; i--)
    {
        for(int buy = 0 ; buy <= 1 ; buy++)
        {
            for(int cap = 1 ; cap <= 2 ; cap++)
            {
                if(buy == 0)
                {
                    dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                }
                else
                {
                    dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap],dp[i+1][1][cap]);
                }
            }

        }
    }

    return dp[0][1][2];

}