using Microsoft.VisualStudio.TestTools.UnitTesting;
using Problem3Solution;
namespace TestProblem3
{
    [TestClass]
    public class TestProblem3
    {
        [TestMethod]
        public void Permutation_Of_Palindrome_Is_True()
        {
            var solution = new Problem3();

            string expected = "YES";
            string input = "carroaco";

            string result = solution.isPalindromePermutation(input);

            Assert.AreEqual(expected, result);
        }

        [TestMethod]
        public void Permutation_Of_Palindrome_Is_False()
        {
            var solution = new Problem3();

            string expected = "NO";
            string input = "abcabcabc";

            string result = solution.isPalindromePermutation(input);

            Assert.AreEqual(expected, result);
        }
    }
}
