using System;
using System.Collections.Generic;

namespace Problem3Solution
{
    public class Problem3
    {
        public string isPalindromePermutation(string palindrome)
        {
            var ss = palindrome.ToLower();

            var charTable = new Dictionary<char, int>();
            for (int i = 0; i < ss.Length ;i++)
                {
                if(charTable.ContainsKey(ss[i]))
                {
                    charTable[ss[i]]++;
                }
                else
                {
                    charTable.Add(ss[i], 1);
                }
            }

            int odd = 0;
            foreach (var item in charTable)
            {
                odd += item.Value % 2 != 0 ? 1 : 0;
            }
            if(odd > 1)
            {
                return "NO";
            }
            return "YES";
        }
    }
}
