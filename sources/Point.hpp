#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        // **** declare attributes ****
        double x_axis_;
        double y_axis_;
    public:
        // **** declare constructors ****
        Point(); // default constructor
        Point(double x_axis,double y_axis); // constructor get 2 valuse for x,y axises

        // **** declare getters ****
        double getX() const; // this return the X axis value
        double getY() const; // this return the Y axis value


        // **** declare functions ****
        double getDistance(const Point& other) const; // this function get another point and calculate the distance between them
        void printPoint(); // this function return the value of the point in string in this format (X,Y)
        static Point moveTowards(const Point& src, const Point& dst, double dist); // this function get 2 points and distance and return the closet point to the destination point from the source point

    };
}