#include <gtest/gtest.h>
#include "Engine.h"

using namespace sre;

TEST(EngineTest, CreateEngine)
{
   Engine* engine = Engine::create();
   ASSERT_TRUE(engine != nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
