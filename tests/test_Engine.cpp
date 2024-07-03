#include <gtest/gtest.h>
#include "EngineManager.h"

using namespace sre;

TEST(EngineTestSuite, CreateEngine)
{
    ASSERT_NO_THROW({
        EngineManager e;
        Engine& engine = e.create();});
   
}

TEST(EngineTestSuite, InitializeEngine)
{
    ASSERT_NO_THROW({
        EngineManager e;
        Engine& engine = e.create();
        engine.initialize("TestName");
    });
}

TEST(EngineTestSuite, DestroyEngine)
{
    ASSERT_NO_THROW({
        EngineManager e;
        Engine& engine = e.create();
        e.destroy();
    });
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
