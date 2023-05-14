#include "doctest.h"
#include "sources/Team.hpp"
#include <cmath>
#include <limits>

using namespace std;
using namespace ariel;

// from chatgpt to compare 2 double numbers due the precission 
bool isEqual(double a, double b, double tolerance = 1e-4) {
    return fabs(a - b) < tolerance;
}


TEST_SUITE("Point class tests")
{
    TEST_CASE("Parameterized constructor")
    {
        CHECK_NOTHROW(Point (3, 4)); // positive integer parameterized constrcutor
        CHECK_NOTHROW(Point (3.22, 4.24)); //  positive double parameterized constrcutor
        CHECK_NOTHROW(Point (-3, -1)); // negative integer parameterized constrcutor
        CHECK_NOTHROW(Point (-3.1121, -4.343)); //  negative double parameterized constrcutor
        CHECK_NOTHROW(Point (3, -4.555)); //  mix double parameterized constrcutor

        Point a(3, 4); // positive integer
        Point b(1.5, 2.5); // positive double
        Point c(-1.5, 3); // mix

        CHECK_EQ(a.getX(), 3);
        CHECK_EQ(a.getY(), 4);

        CHECK_EQ(b.getX(), 1.5);
        CHECK_EQ(b.getY(), 2.5);

        CHECK_EQ(c.getX(), -1.5);
        CHECK_EQ(c.getY(), 3);
    }

    TEST_CASE("default constructor")
    {
        CHECK_NOTHROW(Point());

        Point a;
        CHECK_EQ(a.getX(), 0);
        CHECK_EQ(a.getY(), 0);
    }

    TEST_CASE("distance function")
    {
        // positive integers
        Point a(1, 3);
        Point b(1, 8);

        CHECK_NOTHROW(a.getDistance(b));
        CHECK_EQ(a.getDistance(b), 5);

        // negative integers
        Point c(-1, -3);
        Point d(-1, -8);


        CHECK_NOTHROW(c.getDistance(d));
        CHECK_EQ(c.getDistance(d), 5);

        // positive double
        Point e(1.5, 3.5);
        Point f(1.5, 8.5);

        CHECK_NOTHROW(e.getDistance(f));
        CHECK_EQ(e.getDistance(f), 5);

        // negative double
        Point g(-1.5, -3.5);
        Point h(-1.5, -8.5);

        CHECK_NOTHROW(e.getDistance(f));
        CHECK_EQ(e.getDistance(f), 5);

        // mix double
        Point i(1.5, 3.5);
        Point j(-1.5, -8.5);

        CHECK_NOTHROW(i.getDistance(j));
        CHECK(isEqual(i.getDistance(j), 12.3693));
    }

    TEST_CASE("moveTowards function")
    {
        Point a(1, 3);
        Point b(1, 8);

        CHECK_NOTHROW(Point::moveTowards(a, b, 5));

        CHECK_EQ(Point::moveTowards(a, b, 5).getX(),1);
        CHECK_EQ(Point::moveTowards(a, b, 5).getY(),8);

        CHECK_EQ(Point::moveTowards(a, b, 0).getX(), 1);
        CHECK_EQ(Point::moveTowards(a, b, 0).getY(), 3);
    }
}

TEST_SUITE("Young Ninja class test")
{
    TEST_CASE("constructor test")
    {
        CHECK_NOTHROW(YoungNinja()); // default constructor
        CHECK_NOTHROW(YoungNinja("ravid", Point())); // default constructor

        YoungNinja* a = new YoungNinja();
        YoungNinja* b = new YoungNinja("ravid", Point(2.5, 3));

        // check if hp level initialized to 100
        CHECK_EQ(a->getHpLevel(), 100);
        CHECK_EQ(b->getHpLevel(), 100);

        // check name initialization
        CHECK_EQ(a->getName(), "anonYoungNinja");
        CHECK_EQ(b->getName(), "ravid");

        // check speed intialized to 14
        CHECK_EQ(a->getSpeed(), 14);
        CHECK_EQ(b->getSpeed(), 14);

        // check coordinate initialization
        CHECK_EQ(a->getLocation().getX(), 0);
        CHECK_EQ(a->getLocation().getY(), 0);
        CHECK_EQ(b->getLocation().getX(), 2.5);
        CHECK_EQ(b->getLocation().getY(), 3);
    }

    TEST_CASE("move function")
    {
        YoungNinja* a = new YoungNinja("ravid", Point());
        YoungNinja* b = new YoungNinja("talia", Point(0, 40));

        CHECK_NOTHROW(a->move(b));

        CHECK_EQ(a->getLocation().getX(), 0);
        CHECK_EQ(a->getLocation().getY(), 14);
    }

    TEST_CASE("slash function")
    {
        // check if nothing happen when foe is more than 1 meter far
        YoungNinja* a = new YoungNinja("ravid", Point());
        YoungNinja* b = new YoungNinja("talia", Point(0, 40));

        CHECK_THROWS(a->slash(a)); // check if exception thrown when ninja want to slash itself
        CHECK_NOTHROW(a->slash(b));
        CHECK_EQ(b->getHpLevel(), 100); // same hp level as initialized

        //check if nothing happen when foe is exactly 1 meter far
        YoungNinja* c = new YoungNinja("ravid", Point());
        YoungNinja* d = new YoungNinja("talia", Point(0, 1));

        CHECK_NOTHROW(c->slash(d));
        CHECK_EQ(d->getHpLevel(), 100); // same hp level as initialized

        // check if slash is happening when foe is less than 1 meter far
        YoungNinja* e = new YoungNinja("ravid", Point());
        YoungNinja* f = new YoungNinja("talia", Point(0, 0.9));

        CHECK_NOTHROW(e->slash(f));
        CHECK_EQ(f->getHpLevel(), 60); // same hp level as initialized
    }
}
TEST_SUITE("Old Ninja class test")
{
    TEST_CASE("constructor test")
    {
        CHECK_NOTHROW(OldNinja()); // default constructor
        CHECK_NOTHROW(OldNinja("ravid", Point())); // parameterized constructor

        OldNinja* a = new OldNinja();
        OldNinja* b = new OldNinja("ravid", Point(2.5, 3));

        // check if hp level initialized to 100
        CHECK_EQ(a->getHpLevel(), 140);
        CHECK_EQ(b->getHpLevel(), 140);

        // check name initialization
        CHECK_EQ(a->getName(), "anonOldNinja");
        CHECK_EQ(b->getName(), "ravid");

        // check speed intialized to 14
        CHECK_EQ(a->getSpeed(), 8);
        CHECK_EQ(b->getSpeed(), 8);

        // check coordinate initialization
        CHECK_EQ(a->getLocation().getX(), 0);
        CHECK_EQ(a->getLocation().getY(), 0);
        CHECK_EQ(b->getLocation().getX(), 2.5);
        CHECK_EQ(b->getLocation().getY(), 3);
    }

    TEST_CASE("move function")
    {
        OldNinja* a = new OldNinja("ravid", Point());
        OldNinja* b = new OldNinja("talia", Point(0, 40));

        CHECK_NOTHROW(a->move(b));

        CHECK_EQ(a->getLocation().getX(), 0);
        CHECK_EQ(a->getLocation().getY(), 8);
    }

    TEST_CASE("slash function")
    {
        // check if nothing happen when foe is more than 1 meter far
        OldNinja* a = new OldNinja("ravid", Point());
        OldNinja* b = new OldNinja("talia", Point(0, 40));

        CHECK_THROWS(a->slash(a)); // check if exception thrown when ninja want to slash itself
        CHECK_NOTHROW(a->slash(b));
        CHECK_EQ(b->getHpLevel(), 140); // same hp level as initialized

        //check if nothing happen when foe is exactly 1 meter far
        OldNinja* c = new OldNinja("ravid", Point());
        OldNinja* d = new OldNinja("talia", Point(0, 1));

        CHECK_NOTHROW(c->slash(d));
        CHECK_EQ(d->getHpLevel(), 140); // same hp level as initialized

        // check if slash is happening when foe is less than 1 meter far
        OldNinja* e = new OldNinja("ravid", Point());
        OldNinja* f = new OldNinja("talia", Point(0, 0.9));

        CHECK_NOTHROW(e->slash(f));
        CHECK_EQ(f->getHpLevel(), 100); // same hp level as initialized
    }
}
TEST_SUITE("Trained Ninja class test")
{
    TEST_CASE("constructor test")
    {
        CHECK_NOTHROW(TrainedNinja()); // default constructor
        CHECK_NOTHROW(TrainedNinja("ravid", Point())); // parameterized constructor

        TrainedNinja* a = new TrainedNinja();
        TrainedNinja* b = new TrainedNinja("ravid", Point(2.5, 3));

        // check if hp level initialized to 100
        CHECK_EQ(a->getHpLevel(), 120);
        CHECK_EQ(b->getHpLevel(), 120);

        // check name initialization
        CHECK_EQ(a->getName(), "anonTrainedNinja");
        CHECK_EQ(b->getName(), "ravid");

        // check speed intialized to 14
        CHECK_EQ(a->getSpeed(), 12);
        CHECK_EQ(b->getSpeed(), 12);

        // check coordinate initialization
        CHECK_EQ(a->getLocation().getX(), 0);
        CHECK_EQ(a->getLocation().getY(), 0);
        CHECK_EQ(b->getLocation().getX(), 2.5);
        CHECK_EQ(b->getLocation().getY(), 3);
    }

    TEST_CASE("move function")
    {
        TrainedNinja* a = new TrainedNinja("ravid", Point());
        TrainedNinja* b = new TrainedNinja("talia", Point(0, 40));

        CHECK_NOTHROW(a->move(b));

        CHECK_EQ(a->getLocation().getX(), 0);
        CHECK_EQ(a->getLocation().getY(), 12);
    }

    TEST_CASE("slash function")
    {
        // check if nothing happen when foe is more than 1 meter far
        TrainedNinja* a = new TrainedNinja("ravid", Point());
        TrainedNinja* b = new TrainedNinja("talia", Point(0, 40));

        CHECK_THROWS(a->slash(a)); // check if exception thrown when ninja want to slash itself
        CHECK_NOTHROW(a->slash(b));
        CHECK_EQ(b->getHpLevel(), 120); // same hp level as initialized

        //check if nothing happen when foe is exactly 1 meter far
        TrainedNinja* c = new TrainedNinja("ravid", Point());
        TrainedNinja* d = new TrainedNinja("talia", Point(0, 1));

        CHECK_NOTHROW(c->slash(d));
        CHECK_EQ(d->getHpLevel(), 120); // same hp level as initialized

        // check if slash is happening when foe is less than 1 meter far
        TrainedNinja* e = new TrainedNinja("ravid", Point());
        TrainedNinja* f = new TrainedNinja("talia", Point(0, 0.9));

        CHECK_NOTHROW(e->slash(f));
        CHECK_EQ(f->getHpLevel(), 80); // same hp level as initialized
    }
}

TEST_SUITE("Cowboy class")
{
    TEST_CASE("constructor")
    {
        CHECK_NOTHROW(Cowboy()); // default constructor
        CHECK_NOTHROW(Cowboy("ravid", Point())); // parameterized constructor

        Cowboy* a = new Cowboy();
        Cowboy* b = new Cowboy("ravid", Point(1, 2.5));

        // check initialization of names
        CHECK_EQ(a->getName(), "anonCowboy");
        CHECK_EQ(b->getName(), "ravid");

        // check initialization of hp level
        CHECK_EQ(a->getHpLevel(), 110);
        CHECK_EQ(b->getHpLevel(), 110);

        // check initialization of coordinate
        CHECK_EQ(a->getLocation().getX(), 0);
        CHECK_EQ(a->getLocation().getY(), 0);
        CHECK_EQ(b->getLocation().getX(), 1);
        CHECK_EQ(b->getLocation().getY(), 2.5);

        // check initialization of cartridge
        CHECK_EQ(a->getCartridge(), 6);
        CHECK_EQ(b->getCartridge(), 6);
    }

    TEST_CASE("reload function")
    {
        Cowboy* a = new Cowboy("ravid", Point(10, 10));
        Cowboy* b = new Cowboy("avner", Point(10, 9));

        CHECK_NOTHROW(a->reload());
        CHECK_EQ(a->getCartridge(), 12);
    }

    TEST_CASE("shoot function")
    {
        Cowboy* a = new Cowboy("ravid", Point(10, 10));
        Cowboy* b = new Cowboy("avner", Point(10, 9));

        CHECK_NOTHROW(a->shoot(b));
        CHECK_THROWS(a->shoot(a)); // cant shoot itself

        // check if foe hp level down by 10 pt
        CHECK_EQ(b->getHpLevel(), 100);
        // check if attacker cartidge down by 1
        CHECK_EQ(a->getCartridge(), 5);
    }

    TEST_CASE("has bullets function")
    {
        Cowboy* a = new Cowboy("ravid", Point(10, 10));
        Cowboy* b = new Cowboy("avner", Point(10, 9));

        // check if return true when attacker has bullets
        for(int i=0; i < 6; i++)
        {
            CHECK(a->hasBullets());
            a->shoot(b);
        }
        // after 6 rounds attacker supposed to be out of armor
        CHECK_FALSE(a->hasBullets());
    }
}

TEST_SUITE("MIX BATTLE")
{
    TEST_CASE("shoot function")
    {
        Cowboy *cowboy = new Cowboy("cowboy", Point(10, 10));
        YoungNinja *youngNinja = new YoungNinja("youngNinja", Point(5, 5));
        TrainedNinja *trainedNinja = new TrainedNinja("TrainedNinja", Point(7, 7));
        OldNinja *oldNinja = new OldNinja("oldNinja", Point(9, 9));

        // check if cowboy shoot and hit all types of ninjas
        CHECK_NOTHROW(cowboy->shoot(youngNinja));
        CHECK_NOTHROW(cowboy->shoot(oldNinja));
        CHECK_NOTHROW(cowboy->shoot(trainedNinja));

        // check hp level of all ninjas
        CHECK_EQ(youngNinja->getHpLevel(), 90);
        CHECK_EQ(oldNinja->getHpLevel(), 130);
        CHECK_EQ(trainedNinja->getHpLevel(), 110);
    }

    TEST_CASE("slash function")
    {
        Cowboy *cowboy = new Cowboy("cowboy", Point(10, 10));
        YoungNinja *youngNinja = new YoungNinja("youngNinja", Point(5, 5));
        TrainedNinja *trainedNinja = new TrainedNinja("TrainedNinja", Point(7, 7));
        OldNinja *oldNinja = new OldNinja("oldNinja", Point(9, 9));

        CHECK_NOTHROW(youngNinja->slash(cowboy));
        // check if nothing happened because they not less than 1 meter far
        CHECK_EQ(cowboy->getHpLevel(), 110);

        trainedNinja->move(cowboy);
        CHECK_EQ(trainedNinja->getLocation().getX(), 10);
        CHECK_EQ(trainedNinja->getLocation().getY(), 10);
        CHECK_NOTHROW(trainedNinja->slash(cowboy));
        // check if trained ninja succeed slash cowboy
        CHECK_EQ(cowboy->getHpLevel(), 70);
    }
}

TEST_SUITE("Team class")
{
    TEST_CASE("constructor")
    {
        CHECK_NOTHROW(Team ()); // default constructor
        Cowboy *cowboy = new Cowboy("cowboy", Point(10, 10));
        YoungNinja *youngNinja = new YoungNinja("youngNinja", Point(5, 5));
        TrainedNinja *trainedNinja = new TrainedNinja("TrainedNinja", Point(7, 7));
        OldNinja *oldNinja = new OldNinja("oldNinja", Point(9, 9));
        CHECK_NOTHROW(Team a(cowboy)); // parameterized constructor with cowboy
        CHECK_NOTHROW(Team b(youngNinja)); // parameterized constructor with young ninja
        CHECK_NOTHROW(Team c(trainedNinja)); // parameterized constructor with trained ninja
        CHECK_NOTHROW(Team d(oldNinja)); // parameterized constructor with old ninja
    }

}


