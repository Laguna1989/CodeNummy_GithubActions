#include "impl.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

class ImplTest : public TestWithParam<int>
{};

using ImplTestBelowTen = ImplTest;

TEST_P(ImplTestBelowTen, Test)
{
    int const a = GetParam();
    ASSERT_EQ(a*2, my_function(a));
}

INSTANTIATE_TEST_SUITE_P(BelowTen,ImplTestBelowTen, Values(0, 1, 2, -5, 9,10));

using ImplTestAboveTen = ImplTest;

TEST_P(ImplTestAboveTen, Test)
{
    int const a = GetParam();
    ASSERT_EQ(42, my_function(a));
}

INSTANTIATE_TEST_SUITE_P(AboveTen,ImplTestAboveTen, Values(11,12,500));
