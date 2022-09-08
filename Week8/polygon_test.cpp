/*
 * Create RegularPolygon class with two private fields
 * nSides as an int and sideLength as a double.
 *
 * Then make the public fields. A default
 * RegularPolygon field that sets nSides to 3
 * and sideLength to 1.0.
 * Then make a RegularPolygon constructor that
 * accepts a sides and a length and sets nSides
 * to sides and sideLength to length.
 *
 * Then make a getter and setter for nSides.
 * The setter must make sure the input is
 * greater than or equal to 3.
 *
 * Then make a getter and setter for sideLength.
 * Then make a display function that takes in a
 * RegularPolygon and prints out information
 * regarding it, like the number of sides
 * and the side length.
 *
 * Then make a getPerimeter function that
 * returns nSides * sideLength
 * Then make a getArea function that
 * returns the formula for the area of
 * the polygon.
 *
 * Then make a main function outside the class
 * that will make 3 polygons, one without setting
 * the values and 2 with setting the values.
 * Then call display on all of them and print out
 * the area and perimeter for all of them.
 * Created by Kai Devrim on 7/21/22.
*/
#include <algorithm>
#include <cmath>
using namespace std;
class RegularPolygon {
private:
    int nSides;
    double sideLength;
public:
    RegularPolygon() {
        nSides = 3;
        sideLength = 1.0;
    }
    RegularPolygon(int sides, double length) {
        nSides = sides;
        sideLength = length;
    }
    int getNSides() {
        return nSides;
    }
    void setNSides(int sides) {
        if (abs(sides) >= 3) {
            nSides = abs(sides);
        }
    }
    double getSideLength() {
        return sideLength;
    }
    void setSideLength(double length) {
        sideLength = length;
    }
    static void display(RegularPolygon polygon) {
        printf("The Polygon has %i sides and a length of %.3lf", polygon.nSides, polygon.sideLength);
    }
    static double getPerimeter(RegularPolygon polygon) {
        return polygon.nSides * polygon.sideLength;
    }
    static double getArea(RegularPolygon polygon) {
        return ((polygon.nSides * (polygon.sideLength * polygon.sideLength)) / (4 * tan(3.14159 / polygon.nSides)));
    }
};

int main() {
    RegularPolygon polygon1;
    RegularPolygon polygon2(1, 4.0);
    RegularPolygon polygon3(-1, 7.5);
    RegularPolygon::display(polygon1);
    printf("\n");
    RegularPolygon::display(polygon2);
    printf("\n");
    RegularPolygon::display(polygon3);
    printf("\n");
    printf("Polygon 1 Perimeter is: %.3lf\n", RegularPolygon::getPerimeter(polygon1));
    printf("Polygon 2 Perimeter is: %.3lf\n", RegularPolygon::getPerimeter(polygon2));
    printf("Polygon 3 Perimeter is: %.3lf\n", RegularPolygon::getPerimeter(polygon3));

    printf("Polygon 1 Area is: %lf\n", RegularPolygon::getArea(polygon1));
    printf("Polygon 2 Area is: %lf\n", RegularPolygon::getArea(polygon2));
    printf("Polygon 3 Area is: %lf\n", RegularPolygon::getArea(polygon3));

    return 0;
}