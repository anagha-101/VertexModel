// the simple code
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
    Cell() 
    {
        return;
    }
    double get_Area(vector<double>& xa, vector<double>& ya, vector<double>& xb, vector<double>& yb) 
    {
        double area = 0;
        int n = xa.size();
        // Shoelace formula to calculate area
        for (int i = 0; i < n; i++) 
        {
            area += xa[i+1] * ya[i] + xb[(i + 1) % n] * ya[(i + 1) % n] + xb[i] * yb[(i + 1) % n] + xa[i] * yb[i]- xa[i] * ya[(i + 1) % n] - xa[(i + 1) % n] * yb[(i + 1) % n] - xb[(i + 1) % n] * yb[i] - xb[i] * ya[i];
        }
        area = area / 2;
        return area;
    }
    // double get_Area()
    // {
    //     double area = 0;
    //     int n = apical_nodes.size();
    //     // formula to calculate area
    //     for (int i = 0; i < n; i++) 
    //     {
    //         area += apical_nodes[(i + 1) % n].x * apical_nodes[i].y + basal_nodes[(i + 1) % n].x * apical_nodes[(i + 1) % n].y + basal_nodes[i].x * basal_nodes[(i + 1) % n].y + apical_nodes[i].x * basal_nodes[i].y - apical_nodes[i].x * apical_nodes[(i + 1) % n].y - apical_nodes[(i + 1) % n].x * basal_nodes[(i + 1) % n].y - basal_nodes[(i + 1) % n].x * basal_nodes[i].y - basal_nodes[i].x * apical_nodes[i].y;          
    //     }
    //     area = area / 2;
    //     return area;
    // }
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
        for (int i = 0; i < xa.size(); i++)
        {
            cell.push_back(Cell());
            // should we define each cell by i and i+1 vertices?
            // cell[i].apical_nodes.push_back(apical_nodes[i]);
            // cell[i].apical_nodes.push_back(apical_nodes[(i + 1) % xa.size()]);
            // cell[i].basal_nodes.push_back(basal_nodes[i]);
            // cell[i].basal_nodes.push_back(basal_nodes[(i + 1) % xa.size()]);
        }

    }
};

int main() 
{
    // input vertex coordinates, fill in advance
    vector<double> xa = {1,2,3,4,5,6}, ya = {2,2,2,2,2,2}, xb = {1,2,3,4,5,6}, yb = {1,1,1,1,1,1};

    System S(xa,ya,xb,yb);
    cout << "Area of a Cell: " << S.cell[2].get_Area(xa,xb,ya,yb) << endl;
    // changing a single vertex coordinate to see impact on nearby cell
    // if third vertex is changed from (3,2) to (10,2) then area of cell 2 and cell 3 should change
    xa[2] = 10;
    System S_new(xa,ya,xb,yb);
    cout << "Area of second Cell: " << S_new.cell[2].get_Area(xa,xb,ya,yb) << endl;
    cout << "Area of third Cell: " << S_new.cell[3].get_Area(xa,xb,ya,yb) << endl;
    cout << "Area of fourth Cell: " << S_new.cell[4].get_Area(xa,xb,ya,yb) << endl;
    return 0;
}
