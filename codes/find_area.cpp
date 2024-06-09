// This code calculates the area and perimeter of a cell with given vertices
// The main purpose of this exercise is to familiarize with the concept of classes and objects

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Vertices{
    public:
    // for a 2D cell (x,y) are the vertex coordinates
    // these are members of the class
    double x;
    double y;
    // constructor to initialize the vertices
    Vertices(double x1, double y1)
    {
    x = x1;
    y = y1;
    }
};

class Cell{
    public:
    // nodes is a vector of vertices
    vector<Vertices>nodes;

    // Shoelace's formula to calculate the area of the cell
    double get_Area(){
        // initialise area
        double area = 0;
        // loop through the vertices
        for (int i = 0; i < nodes.size(); i ++){
            // area calculated using the Shoelace formula
            area += nodes[i].x * nodes[(i+1) % nodes.size()].y - nodes[(i+1) % nodes.size()].x * nodes[i].y;
        }
        // changed abs area, since area can be negative
        area = area / 2;
        return area;
    }

    double get_Perimeter(){
        // initialise perimeter
        double perimeter = 0;
        // loop through the vertices
        for (int i = 0; i < nodes.size(); i++){
            // find distance between vertices
            double distance = sqrt(pow(nodes[i].x - nodes[(i+1) % nodes.size()].x, 2) + pow(nodes[i].y - nodes[(i+1) % nodes.size()].y, 2));
            // add distance to perimeter
            perimeter += distance;         
        }
        return perimeter;
    }
};
// main function will create an object of the class Cell and calculate the area and perimeter
int main(){
    // declare an object of the class Cell
    Cell C;
    // assign vertices to the object
    C.nodes = { {10, 7}, {5, 11}, {2, 8}, {2, 3},{5, 1}, {10, 4}};
    // calculate the area
    double area = C.get_Area();
    // calculate the perimeter
    double perimeter = C.get_Perimeter();
    // print the area and perimeter
    cout << "Area of the cell is: " << area << endl;
    cout << "Perimeter of the cell is: " << perimeter << endl;
    return 0;

}