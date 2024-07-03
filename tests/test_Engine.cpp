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
        EngineTest::engine.initialize("TestName");
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
