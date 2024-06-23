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
