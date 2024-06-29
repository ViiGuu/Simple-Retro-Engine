#include <gtest/gtest.h>
#include "Engine.h"

using namespace sre;

//TODO: fix test
// TEST(EngineTest, CreateEngine)
// {
//     std::unique_ptr<Engine> engine = Engine::create();
//     ASSERT_TRUE(engine != nullptr);
// }

// //Sample tests to make sure Google Test works

// TEST(SampleTest, TestAddition) //should pass
// {
//     EXPECT_EQ(2 + 2, 4);
// }

// TEST(SampleTest, TestSubtraction) //should fail
// {
//     EXPECT_EQ(2 - 3, 0);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
