int maxProfit(int *prices, int pricesSize){
    if(pricesSize<=0)
        return 0;
    int i;
    int profit = 0;
    int price = prices[0];
    for(i=1;i<pricesSize;i++)
    {
        if(prices[i]<price)
            price = prices[i];
        if(profit<prices[i]-price)
            profit=prices[i]-price;
    }
    return profit;

}
