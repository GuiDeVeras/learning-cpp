#include <gtest/gtest.h>

#include <vector>

int Add(int a, int b) { return a + b; }

TEST(Add, TwoNumbers) {
  EXPECT_EQ(Add(2, 3), 5);
}

TEST(Vector, PushBackIncreasesSize) {
  std::vector<int> v;
  v.push_back(1);
  ASSERT_EQ(v.size(), 1u);
  EXPECT_EQ(v[0], 1);
}

// Leaks on purpose: passes in a normal build, but the sanitizer should complain.
TEST(Sanitizers, Leak) {
  auto p = std::make_unique<int>(42);
  EXPECT_EQ(*p, 42);
}
