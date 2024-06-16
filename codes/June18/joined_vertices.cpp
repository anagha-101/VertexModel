// In this code apical and basal vertices are joined to form cells
// and the area and perimeter of the cells are calculated
// By default, the cells are squares with side length 1
// The number of vertices can be changed by changing the value of N

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Vertices {
public:
    double x, y;
    // constructor to initialize the vertices
    Vertices(double x1, double y1) {
        x = x1;
        y = y1;
    }
};

class Cell {
public:
    vector<Vertices> nodes;
    // constructor to initialize the vertices of the cell
    Cell(const vector<Vertices>& input_nodes) {
        nodes = input_nodes;
    }

    double get_Area() {
        double area = 0;
        // Shoelace formula to calculate area of a polygon
        for (int i = 0; i < nodes.size(); i++) {
            area += nodes[i].x * nodes[(i + 1) % nodes.size()].y - nodes[(i + 1) % nodes.size()].x * nodes[i].y;
        }
        area = area / 2;
        return area;
    }

    double get_Perimeter() {
        double perimeter = 0;
        // distance between each pair of vertices is calculated and summed up to get the perimeter
        for (int i = 0; i < nodes.size(); i++) {
            double distance = sqrt(pow(nodes[i].x - nodes[(i + 1) % nodes.size()].x, 2) + pow(nodes[i].y - nodes[(i + 1) % nodes.size()].y, 2));
            perimeter += distance;
        }
        return perimeter;
    }
};

class System {
public:
    vector<Vertices> apical_nodes;
    vector<Vertices> basal_nodes;
    vector<Cell> cells;
    double x, y;

    // constructor to initialize the system with N apical vertices and N basal vertices
    System(int N, double x, double y) : x(x), y(y) {
        for (int i = 0; i < N; i++) {
            // change the value of 1 in y + 1 to increase or decrease the height of the cells
            // right now the height is 1
            apical_nodes.push_back(Vertices(x + i, y + 1));  // Apical vertices
            basal_nodes.push_back(Vertices(x + i, y));       // Basal vertices
        }
        
        // Print the apical and basal vertices
        cout << "Apical vertices: ";
        for (const auto& vertex : apical_nodes) {
            cout << "(" << vertex.x << ", " << vertex.y << ") ";
        }
        cout << endl;

        cout << "Basal vertices: ";
        for (const auto& vertex : basal_nodes) {
            cout << "(" << vertex.x << ", " << vertex.y << ") ";
        }
        cout << endl;

        // Create cells using apical and basal vertices
        for (int i = 0; i < N - 1; i++) {
            vector<Vertices> nodes = {
                apical_nodes[i], basal_nodes[i],
                basal_nodes[i + 1], apical_nodes[i + 1]
            };
            cells.push_back(Cell(nodes));
            // Print the cell vertices
            cout << "Cell " << i + 1 << " vertices: ";
            for (const auto& vertex : nodes) {
                cout << "(" << vertex.x << ", " << vertex.y << ") ";
            }
            cout << endl;
        }
    }

    double getTotalArea() {
        double total_area = 0;
        for (Cell& cell : cells) {
            total_area += cell.get_Area();
        }
        return total_area;
    }
    
    double getTotalPerimeter() {
        double total_perimeter = 0;
        for (Cell& cell : cells) {
            total_perimeter += cell.get_Perimeter();
        }
        return total_perimeter;
    }
};

int main() {
    // N is the number of initial nodes for the System
    // note that the number of cells is always N - 1
    // here 6 nodes implies 5 cells
    int N = 6;  
    double x = 0, y = 0;

    // Initialize the System S with N, x, and y
    System S(N, x, y);

    double area_of_a_cell = S.cells[0].get_Area();
    double perimeter_of_a_cell = S.cells[0].get_Perimeter();
    double total_area = S.getTotalArea();
    double total_perimeter = S.getTotalPerimeter();

    cout << "Area of a Cell: " << area_of_a_cell << endl;
    cout << "Perimeter of a Cell: " << perimeter_of_a_cell << endl;
    cout << "Total Area: " << total_area << endl;
    cout << "Total Perimeter: " << total_perimeter << endl;
    
    return 0;
}
