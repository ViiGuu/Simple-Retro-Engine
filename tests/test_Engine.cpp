#include <gtest/gtest.h>
#include "Engine.h"
#include "EngineManager.h"

using namespace sre;

TEST(EngineTest, CreateEngine)
{
    ASSERT_NO_THROW({
        EngineManager engineManager;
        Engine& engine = engineManager.create();
        });

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
