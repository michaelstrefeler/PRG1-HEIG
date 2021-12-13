/**
 * @file Point.cpp
 * @author Michael Strefeler
 * @brief Class functions
 * @version 0.1
 * @date 06-12-2021
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <cmath>
#include "Point.hpp"

/**
 * @brief Construct a new Point:: Point object
 *
 * @param abscissa horizontal coordinate
 * @param ordinate vertical coordinate
 */
Point::Point(float abscissa, float ordinate)
{
    x = abscissa;
    y = ordinate;
}

/**
 * @brief Move the point on the plane
 *
 * @param move_x move horizonatly
 * @param move_y move vertically
 */
void Point::move(float move_x, float move_y)
{
    x += move_x;
    y += move_y;
}

/**
 * @brief Returns x coordinate
 *
 * @return float
 */
float Point::abscissa() const
{
    return x;
}

/**
 * @brief Returns y coordinate
 *
 * @return float
 */
float Point::ordinate() const
{
    return y;
}

/**
 * @brief Add the coordinates of two points together
 *
 * @param right right hand side of addition
 * @return point corresponding to the result of the addition
 */
Point Point::operator+(const Point &right) const
{
    return Point(this->x + right.x, this->y + right.y);
}

float Point::rho() const
{
    return hypot(x, y);
}

float Point::theta() const
{
    return atan2(y, x);
}