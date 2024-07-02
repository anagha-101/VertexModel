// energy formula code
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
    // energy calculation
    // edge length is calculated by the euclidean distance 
    double get_E_cell_edge(vector<double>& xa, vector<double>& ya, vector<double>& xb, vector<double>& yb) 
    {   
        // tension (change as required)
        double alpha_a = 1, alpha_b = 1, alpha_l = 1;
        double E_cell_edge = 0;
        int n = xa.size();
        for (int i = 0; i < n-1; i++) 
        {
            E_cell_edge += alpha_a * sqrt(pow(xa[i] - xa[(i + 1) % n], 2) + pow(ya[i] - ya[(i + 1) % n], 2)) +
                           alpha_b * sqrt(pow(xb[i] - xb[(i + 1) % n], 2) + pow(yb[i] - yb[(i + 1) % n], 2))+
                           alpha_l * sqrt(pow(xa[i] - xb[i], 2) + pow(ya[i] - yb[i], 2));
        }
        return E_cell_edge;
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
    cout << "Energy of a Cell: " << S.cell[2].get_E_cell_edge(xa,ya,xb,yb) << endl;
    return 0;
}
