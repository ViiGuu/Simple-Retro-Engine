#include <gtest/gtest.h>
#include "EngineManager.h"
#include <SDL.h>

using namespace sre;


class EngineTest : public ::testing::Test {
protected:
    EngineManager engineManager;
    Engine& engine = engineManager.create();
};

TEST(EngineTestSuite, CreateEngine)
{
    ASSERT_NO_THROW({
        EngineManager e;
        Engine& engine = e.create();});
}

TEST_F(EngineTest, InitializeEngine)
{
    ASSERT_NO_THROW({
        engine.initialize("TestName");
    });

    ASSERT_TRUE(EngineTest::engine.isInitialized());
}

TEST_F(EngineTest, DestroyEngine)
{
    ASSERT_NO_THROW({
        engineManager.destroy();
    });
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
