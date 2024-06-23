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
    vector<Vertices> apical_nodes;
    vector<Vertices> basal_nodes;
    // constructor 
    Cell() {
        return;
    }

    double get_Area() {
        double area = 0;
        int n = apical_nodes.size(); // Assuming apical_nodes and basal_nodes have the same size

        // Shoelace formula to calculate area of a polygon formed by apical nodes
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            area += (apical_nodes[i].x * apical_nodes[j].y - apical_nodes[j].x * apical_nodes[i].y);
        }

        // Shoelace formula to calculate area of a polygon formed by basal nodes
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            area += (basal_nodes[i].x * basal_nodes[j].y - basal_nodes[j].x * basal_nodes[i].y);
        }

        area = abs(area) / 2.0;
        return area;
    }
};

class System {
public:
    vector<Vertices> apical_nodes;
    vector<Vertices> basal_nodes;
    vector<Cell> cells;

    // constructor
    System(vector<double>& xa, vector<double>& ya, vector<double>& xb, vector<double>& yb) {
        // vertex initialization
        for (int i = 0; i < xa.size(); i++) {
            apical_nodes.push_back(Vertices(xa[i], ya[i]));  // Apical vertices
            basal_nodes.push_back(Vertices(xb[i], yb[i]));   // Basal vertices
        }

        // cell initialization
        for (int i = 0; i < xa.size(); i++) {
            Cell cell;
            cell.apical_nodes.push_back(apical_nodes[i]);
            cell.basal_nodes.push_back(basal_nodes[i]);
            cells.push_back(cell);
        }
    }
};

int main() {
    // input vertex coordinates forming closed polygons
    vector<double> xa = {0, 1, 1, 0};
    vector<double> ya = {0, 0, 1, 1};
    vector<double> xb = {0, 1, 1, 0};
    vector<double> yb = {0, 0, 1, 1};

    System S(xa, ya, xb, yb);

    double area_of_a_cell = S.cells[0].get_Area();
    cout << "Area of a Cell: " << area_of_a_cell << endl;

    return 0;
}
