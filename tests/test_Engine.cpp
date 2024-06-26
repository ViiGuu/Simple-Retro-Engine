#include <gtest/gtest.h>
#include "Engine.h"

TEST(EngineTest, MethodNameTest) { //sample test
    Engine engine;
    std::string testString = "Stuff done B)";
    EXPECT_EQ(engine.doStuff(), testString);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
