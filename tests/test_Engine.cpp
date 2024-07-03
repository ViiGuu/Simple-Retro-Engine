#include <gtest/gtest.h>
#include "EngineManager.h"

using namespace sre;

TEST(EngineTest, CreateEngine)
{
    ASSERT_NO_THROW({
        EngineManager e;
        Engine& engine = e.create();});
   
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
