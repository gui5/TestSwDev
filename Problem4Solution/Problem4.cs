using System;

namespace Problem4Solution
{
    public class Problem4
    {
        private readonly int[] _coins = { 1, 5, 10, 20, 25 };

        /// <summary>
        /// Calculate the number of ways to compose a given amount with the available coins.
        /// </summary>
        /// <param name="cents"></param>
        /// <returns></returns>
        public int getNumberOfCombinations(int cents)
        {
            int[] dp = new int[cents + 1];
            dp[0] = 1;

            foreach (var coin in _coins)
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
