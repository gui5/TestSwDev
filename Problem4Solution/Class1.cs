using System;

namespace Problem4Solution
{
    public class Problem4
    {
        private readonly int[] coins = { 1, 5, 10, 20, 25 };
        public int getNumberOfCombinations(int cents)
        {
            int[] dp = new int[cents + 1];
            dp[0] = 1;

            foreach (var coin in coins)
            {
                for (int i = coin; i <= cents; i++)
                {
                    dp[i] += dp[i - coin];
                }
            }

            return dp[cents];
        }
    }
}
