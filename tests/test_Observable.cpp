#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SDL.h>
#include "Observer.h"
#include "Observable.h"

class TestObserver : public sre::Observer
{
    public: 
        TestObserver() : testOutput("nothing") {};
        void update() override {testOutput = "updated";}
        std::string getOutput(){ return testOutput;}
    private:
        std::string testOutput;

};

class TestObservable : public sre::Observable
{
    public:
        TestObservable() = default;
        ~TestObservable() = default;
};

class ObserverObservableTest : public ::testing::Test 
{
    protected:
        void SetUp() override 
        {
            subject = new TestObservable();
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

        TestObservable* subject;
        TestObserver* observer1;
        TestObserver* observer2;
};

TEST_F(ObserverObservableTest, AddObserver) 
{
    subject->add(observer1);
    EXPECT_EQ(1, subject->getObservers().size());
}

TEST_F(ObserverObservableTest, AddSameObserverTwice) 
{
    subject->add(observer1);
    subject->add(observer1);
    EXPECT_EQ(1, subject->getObservers().size());
}

TEST_F(ObserverObservableTest, AddNullptr)
{
    TestObserver* nullObs = nullptr;
    subject->add(nullObs);
    EXPECT_EQ(0, subject->getObservers().size());
}

TEST_F(ObserverObservableTest, RemoveObserver) 
{
    subject->add(observer1);
    subject->add(observer2);
    EXPECT_EQ(2, subject->getObservers().size());

    subject->remove(observer1);
    EXPECT_EQ(1, subject->getObservers().size());
}

TEST_F(ObserverObservableTest, RemoveNonexistentObserver) 
{
    subject->add(observer1);
    EXPECT_EQ(1, subject->getObservers().size());

    TestObserver* nonexistentObserver;
    subject->remove(nonexistentObserver);
    EXPECT_EQ(1, subject->getObservers().size());
}

TEST_F(ObserverObservableTest, NotifyObservers) 
{
    subject->add(observer1);
    subject->add(observer2);

    EXPECT_EQ("nothing", observer1->getOutput());
    EXPECT_EQ("nothing", observer2->getOutput());

    subject->notify();

    EXPECT_EQ("updated", observer1->getOutput());
    EXPECT_EQ("updated", observer2->getOutput());
}


TEST_F(ObserverObservableTest, NotifyEmptyObserverList) 
{
    EXPECT_NO_THROW(subject->notify());
}