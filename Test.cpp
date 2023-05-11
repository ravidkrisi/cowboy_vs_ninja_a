#include "doctest.h"
#include "sources/Point.hpp"

using namespace std;
using namespace ariel;
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

        CHECK_EQ(a.getX(), -1.5);
        CHECK_EQ(a.getY(), 3);
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
        CHECK_EQ(i.getDistance(j), 11.1803);
    }
    // need to check how to compare output
    TEST_CASE("printPoint function")
    {
        Point a(1.5, 2.0);
        CHECK_NOTHROW(a.printPoint());
    }

    TEST_CASE("moveTowards function")
    {
        Point a(1, 3);
        Point b(1, 8);

        CHECK_NOTHROW(Point::moveTowards(a, b, 5));

        CHECK_EQ(Point::moveTowards(a, b, 5).getX(),1);
        CHECK_EQ(Point::moveTowards(a, b, 5).getY(),8);

        CHECK_EQ(Point::moveTowards(a, b, 0).getX(), 1);
        CHECK_EQ(Point::moveTowards(a, b, 0).getX(), 3);
    }
}