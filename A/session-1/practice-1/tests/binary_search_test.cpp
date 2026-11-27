#include <gtest/gtest.h>

#include "binary_search.h"
#include <vector>

TEST(BinarySearch, ReturnFalseEmptyVector) {
	std::vector<int> empty_vector;
	EXPECT_EQ(BinarySearch(empty_vector, 3), false);
}
