#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "EngineManager.h"
#include "WindowInterface.h"
#include "RendererInterface.h"
#include <SDL.h>

using namespace sre;

class EngineTest : public ::testing::Test {
protected:
    EngineManager engineManager;
    Engine& engine = engineManager.create();
};

//Basic Engine tests

//TODO: tests broke after refactoring, fix.

TEST(EngineTestSuite, CreateEngine)
{
    ASSERT_NO_THROW({
        EngineManager e;
        Engine& engine = e.create();});
}

TEST_F(EngineTest, InitializeEngine) //FAILED
{
    ASSERT_TRUE(EngineTest::engine.isInitialized());
}

TEST_F(EngineTest, DestroyEngine)
{
    ASSERT_NO_THROW({
        engineManager.destroy();
    });
}

// failed because window gets initialised automatically by EngineManager
// TEST_F(EngineTest, NullWindow)
// {
//    EXPECT_THROW({
//         try {
//             engine.getWindow();
//         } catch (const std::runtime_error& e) {
//             EXPECT_STREQ("Window has not been initialized", e.what());
//             throw;
//         }
//     }, std::runtime_error);
// }

TEST_F(EngineTest, NotNullWindow)
{
    EXPECT_NO_THROW({
        WindowInterface& window = engine.getWindow();
        EXPECT_NE(&window, nullptr);
    });
}

// failed because renderer gets initialised automatically by EngineManager
// TEST_F(EngineTest, NullRenderer)
// {
//      EXPECT_THROW({ 
//         try {
//             engine.getRenderer();
//         } catch (const std::runtime_error& e) {
//             EXPECT_STREQ("Renderer has not been initialized", e.what());
//             throw;
//         }
//     }, std::runtime_error);
// }

TEST_F(EngineTest, NotNullRenderer)
{
    EXPECT_NO_THROW({
        RendererInterface& renderer = engine.getRenderer();
        EXPECT_NE(&renderer, nullptr);
    });
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
