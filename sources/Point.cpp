#include "Point.hpp"
#include <cmath>
#include <iostream>


namespace ariel
{
    // **** define constructors ****

    Point::Point(): x_axis_(0), y_axis_(0) {} // default constructor
    Point::Point(double x_axis, double y_axis): x_axis_(x_axis), y_axis_(y_axis){} // parameterized constructor

    // **** define getters ****

    // this return the value of the x axis
    double Point::getX() const {return this->x_axis_;}
    // this return the value of the y axis
    double Point::getY() const {return this->y_axis_;}

    // **** define functions ****

    // this function get another point and calculate the distance between them
    double Point::getDistance(const Point &other) const
    {
        return std::sqrt(std::pow(this->getX()-other.getX(), 2)+std::pow(this->getY()-other.getY(), 2));
    }

    // this function return the value of the point in string in this format (X,Y)
    string Point::print () const
    {
        return "(" + to_string(this->getX()) + "," + to_string(this->getY()) + ")";
    }

    // this function get 2 points and distance and return the closet point to the destination point from the source point
    Point Point::moveTowards(const Point &src, const Point &dst, double dist_src)
    {
        double dist = src.getDistance(dst); // calc the distance between src and dst

        // Calculate the direction vector between the two points
        double dx = (dst.getX() - src.getX()) / dist;
        double dy = (dst.getY() - src.getY()) / dist;

        double closet_x = src.getX() + dx * dist_src;
        double closet_y = src.getY() + dy * dist_src;

        return Point (closet_x, closet_y);
    }
}
