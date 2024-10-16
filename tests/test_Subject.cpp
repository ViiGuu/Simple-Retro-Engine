#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SDL.h>
#include "Observer.h"
#include "Subject.h"

class TestObserver : public sre::Observer
{
    public: 
        TestObserver() : testOutput("nothing") {};
        void update() override {testOutput = "updated";}
        std::string getOutput(){ return testOutput;}
    private:
        std::string testOutput;

};

class TestSubject : public sre::Subject
{
    public:
        TestSubject() = default;
        ~TestSubject() = default;
};

class ObserverSubjectTest : public ::testing::Test 
{
    protected:
        void SetUp() override 
        {
            subject = new TestSubject();
            observer1 = new TestObserver();
            observer2 = new TestObserver();
        }

        void TearDown() override 
        {
            delete subject;
            subject = nullptr;
            delete observer1;
            observer1 = nullptr;
            delete observer2;
            observer2 = nullptr;
        }

        TestSubject* subject;
        TestObserver* observer1;
        TestObserver* observer2;
};

TEST_F(ObserverSubjectTest, AddObserver) 
{
    subject->add(observer1);
    EXPECT_EQ(1, subject->getObservers().size());
}

TEST_F(ObserverSubjectTest, AddSameObserverTwice) 
{
    subject->add(observer1);
    subject->add(observer1);
    EXPECT_EQ(1, subject->getObservers().size());
}

TEST_F(ObserverSubjectTest, AddNullptr)
{
    TestObserver* nullObs = nullptr;
    subject->add(nullObs);
    EXPECT_EQ(0, subject->getObservers().size());
}

TEST_F(ObserverSubjectTest, RemoveObserver) 
{
    subject->add(observer1);
    subject->add(observer2);
    EXPECT_EQ(2, subject->getObservers().size());

    subject->remove(observer1);
    EXPECT_EQ(1, subject->getObservers().size());
}

TEST_F(ObserverSubjectTest, RemoveNonexistentObserver) 
{
    subject->add(observer1);
    EXPECT_EQ(1, subject->getObservers().size());

    TestObserver* nonexistentObserver;
    subject->remove(nonexistentObserver);
    EXPECT_EQ(1, subject->getObservers().size());
}

TEST_F(ObserverSubjectTest, NotifyObservers) 
{
    subject->add(observer1);
    subject->add(observer2);

    EXPECT_EQ("nothing", observer1->getOutput());
    EXPECT_EQ("nothing", observer2->getOutput());

    subject->notify();

    EXPECT_EQ("updated", observer1->getOutput());
    EXPECT_EQ("updated", observer2->getOutput());
}


TEST_F(ObserverSubjectTest, NotifyEmptyObserverList) 
{
    EXPECT_NO_THROW(subject->notify());
}