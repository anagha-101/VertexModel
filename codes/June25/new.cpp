#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Vertices 
{
public:
    double x, y;
    // constructor 
    Vertices(double x1, double y1) {
        x = x1;
        y = y1;
    }
};

class Cell 
{
public:
    vector<Vertices> apical_nodes;
    vector<Vertices> basal_nodes;
    // constructor 
    Cell(const Vertices& apical1, const Vertices& apical2, const Vertices& basal1, const Vertices& basal2) 
    {
        apical_nodes.push_back(apical1);
        apical_nodes.push_back(apical2);
        basal_nodes.push_back(basal1);
        basal_nodes.push_back(basal2);
    }
    
    double get_Area(vector<double>& xa, vector<double>& ya, vector<double>& xb, vector<double>& yb) 
    {
        double area = 0;
        int n = xa.size();
        // Shoelace formula to calculate area
        for (int i = 0; i < n; i++) 
        {
            int j = (i + 1) % n;  // to wrap around the vertices
            area += xa[j] * ya[i] + xb[j] * ya[j] + xb[i] * yb[j] + xa[i] * yb[i]
                    - xa[i] * ya[j] - xa[j] * yb[j] - xb[j] * yb[i] - xb[i] * ya[i];
        }
        area = area / 2.0;
        return area;
    }
};

class System 
{
public:
    vector<Vertices> apical_nodes;
    vector<Vertices> basal_nodes;
    vector<Cell> cell;
    // constructor
    System(vector<double>& xa, vector<double>& ya, vector<double>& xb, vector<double>& yb)  
    {   
        // vertex initialisation
        for (int i = 0; i < xa.size(); i++) 
        {
            apical_nodes.push_back(Vertices(xa[i], ya[i]));      // Apical vertices
            basal_nodes.push_back(Vertices(xb[i], yb[i]));       // Basal vertices
        }
        // cell initialisation
        for (int i = 0; i < xa.size() - 1; i++) 
        {
            cell.push_back(Cell(apical_nodes[i], apical_nodes[i+1], basal_nodes[i], basal_nodes[i+1]));
        }
    }
};

int main() 
{
    // input vertex coordinates, fill in advance
    vector<double> xa = {1,2,3,4,5,6}, ya = {2,2,2,2,2,2}, xb = {1,2,3,4,5,6}, yb = {1,1,1,1,1,1};

    System S(xa,ya,xb,yb);
    cout << "Area of a Cell: " << S.cell[2].get_Area(xa,ya,xb,yb) << endl;
    return 0;
}

//////////////////////////////////////////////////
// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// class Vertices {
// public:
//     double x, y;
//     Vertices(double x1, double y1) : x(x1), y(y1) {}
// };

// class Cell {
// public:
//     vector<Vertices> apical_nodes;
//     vector<Vertices> basal_nodes;

//     Cell(const vector<Vertices>& apical, const vector<Vertices>& basal) {
//         apical_nodes = apical;
//         basal_nodes = basal;
//     }

//     double get_Area() {
//         double area = 0;
//         int n = apical_nodes.size();
//         for (int i = 0; i < n; i++) {
//             int j = (i + 1) % n;  // Wrap-around index
//             area += apical_nodes[j].x * apical_nodes[i].y 
//                   + basal_nodes[j].x * apical_nodes[j].y 
//                   + basal_nodes[i].x * basal_nodes[j].y 
//                   + apical_nodes[i].x * basal_nodes[i].y 
//                   - apical_nodes[i].x * apical_nodes[j].y 
//                   - apical_nodes[j].x * basal_nodes[j].y 
//                   - basal_nodes[j].x * basal_nodes[i].y 
//                   - basal_nodes[i].x * apical_nodes[i].y;
//         }
//         area = abs(area) / 2.0;
//         return area;
//     }
// };

// class System {
// public:
//     vector<Vertices> apical_nodes;
//     vector<Vertices> basal_nodes;
//     vector<Cell> cells;

//     System(vector<double>& xa, vector<double>& ya, vector<double>& xb, vector<double>& yb) {
//         for (size_t i = 0; i < xa.size(); i++) {
//             apical_nodes.emplace_back(xa[i], ya[i]);
//             basal_nodes.emplace_back(xb[i], yb[i]);
//         }
//         for (size_t i = 0; i < xa.size() - 1; i++) {
//             cells.emplace_back(vector<Vertices>{apical_nodes[i], apical_nodes[i+1]}, 
//                                vector<Vertices>{basal_nodes[i], basal_nodes[i+1]});
//         }
//     }
// };

// int main() {
//     vector<double> xa = {1, 2, 3, 4, 5, 6};
//     vector<double> ya = {2, 2, 2, 2, 2, 2};
//     vector<double> xb = {1, 2, 3, 4, 5, 6};
//     vector<double> yb = {1, 1, 1, 1, 1, 1};

//     System S(xa, ya, xb, yb);

//     double area_of_a_cell = S.cells[2].get_Area();
//     cout << "Area of a Cell: " << area_of_a_cell << endl;

//     // Change a single vertex coordinate to see impact on the area of a cell
//     xa[2] = 10;

//     // Re-create the system to reflect the change
//     System S_updated(xa, ya, xb, yb);
//     area_of_a_cell = S_updated.cells[2].get_Area();
//     cout << "Area of a Cell after changing a vertex: " << area_of_a_cell << endl;

//     return 0;
// }
