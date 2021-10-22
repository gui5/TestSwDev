using Microsoft.VisualStudio.TestTools.UnitTesting;
using Problem4Solution;

namespace TestProblem4
{
    [TestClass]
    public class TestProblem4
    {
        [TestMethod]
        public void TestCase1()
        {
            var solution = new Problem4();

            int input = 10;
            int expected = 4;
            int result = solution.getNumberOfCombinations(input);

            Assert.AreEqual(expected, result);
        }

        [TestMethod]
        public void TestCase2()
        {
            var solution = new Problem4();

            int input = 20;
            int expected = 10;
            int result = solution.getNumberOfCombinations(input);

            Assert.AreEqual(expected, result);
        }
    }
}
