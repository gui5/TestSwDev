#include "pch.h"

TEST(TestProblem1, Case1) {

  auto problem1 = p1::Problem1();

  int m = 1000080;
  int n = 00;

  const std::string expected = "Um milhão e oitenta reais";
  const std::string result = problem1.convertAmount2Words(m, n);

  EXPECT_EQ(expected, result);
}

TEST(TestProblem1, Case2) {

    auto problem1 = p1::Problem1();

    int m = 111;
    int n = 00;

    const std::string expected = "Cento e onze reais";
    const std::string result = problem1.convertAmount2Words(m, n);

    EXPECT_EQ(expected, result);
}

TEST(TestProblem1, Case3) {

    auto problem1 = p1::Problem1();

    int m = 1;
    int n = 11;

    const std::string expected = "Um real e onze centavos";
    const std::string result = problem1.convertAmount2Words(m, n);

    EXPECT_EQ(expected, result);
}

TEST(TestProblem1, Case4) {

    auto problem1 = p1::Problem1();

    int m = 23;
    int n = 01;

    const std::string expected = "Vinte e três reais e um centavo";
    const std::string result = problem1.convertAmount2Words(m, n);

    EXPECT_EQ(expected, result);
}

TEST(TestProblem1, Case5) {

    auto problem1 = p1::Problem1();

    int m = 1000;
    int n = 01;

    const std::string expected = "Mil reais e um centavo";
    const std::string result = problem1.convertAmount2Words(m, n);

    EXPECT_EQ(expected, result);
}

TEST(TestProblem2, Case1) {
    auto problem2 = Problem2();

    const std::string commands = "RRRRDDDLLUUUUUUURRDDDDR";
    const std::string expected = "RRDDDLLUUU";
    const std::string result = problem2.getLastLoop(commands);

    EXPECT_EQ(expected, result);
}