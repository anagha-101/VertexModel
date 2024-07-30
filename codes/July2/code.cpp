// code to calculate energy
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

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
    // constructor 
    Cell() 
    {
        return;
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
        for (int i = 0; i < xa.size(); i++) 
        {
            // vertex initialisation
            apical_nodes.push_back(Vertices(xa[i], ya[i]));      // Apical vertices
            basal_nodes.push_back(Vertices(xb[i], yb[i]));       // Basal vertices
            // cell initialisation
            cell.push_back(Cell());
        }
    }
    
};

int main() 
{
    // input initial vertex coordinates, fill in advance
    vector<double> xa = {1,2,3}, ya = {2,2,2}, xb = {1,2,3}, yb = {1,1,1};
    // vector<double> xa = {1,2,3,4,5,6}, ya = {2,2,2,2,2,2}, xb = {1,2,3,4,5,6}, yb = {1,1,1,1,1,1};
    System S(xa,ya,xb,yb);

    // uncomment to change third cell apical coordinate
    // // S.apical_nodes[2].y = 8;
    // S.apical_nodes[1].y = 8;
    // tension (change as required)
    double alpha_a = 1, alpha_b = 1, alpha_l = 1;
    double E_cell_edge = 0, E_cell_area = 0, E_total = 0;
    double beta = 1, A_0 = 1;
    int n = xa.size();
    for (int i = 0; i < n-1; i++) 
        {
            E_cell_edge += alpha_a * sqrt(((S.apical_nodes[i].x - S.apical_nodes[i+1].x) * (S.apical_nodes[i].x - S.apical_nodes[i+1].x)) + ((S.apical_nodes[i].y - S.apical_nodes[i+1].y) * (S.apical_nodes[i].y - S.apical_nodes[i+1].y))) +
                           alpha_b * sqrt(((S.basal_nodes[i].x - S.basal_nodes[i+1].x ) * (S.basal_nodes[i].x  - S.basal_nodes[i+1].x )) + ((S.basal_nodes[i].y  - S.basal_nodes[i+1].y ) * (S.basal_nodes[i].y  - S.basal_nodes[i+1].y)))+
                           alpha_l * sqrt(((S.apical_nodes[i].x - S.basal_nodes[i].x ) * (S.apical_nodes[i].x - S.basal_nodes[i].x )) + ((S.apical_nodes[i].y - S.basal_nodes[i].y ) * (S.apical_nodes[i].y - S.basal_nodes[i].y)));
            // A_i is given by Shoelace formula
            E_cell_area += beta * ((0.5 * (S.apical_nodes[i+1].x * S.apical_nodes[i].y + S.basal_nodes[i+1].x * S.apical_nodes[i+1].y + S.basal_nodes[i].x * S.basal_nodes[i+1].y + S.apical_nodes[i].x * S.basal_nodes[i].y - S.apical_nodes[i].x * S.apical_nodes[i+1].y - S.apical_nodes[i+1].x * S.basal_nodes[i+1].y - S.basal_nodes[i+1].x * S.basal_nodes[i].y - S.basal_nodes[i].x * S.apical_nodes[i].y)) - A_0) 
                                * ((0.5 * (S.apical_nodes[i+1].x * S.apical_nodes[i].y + S.basal_nodes[i+1].x * S.apical_nodes[i+1].y + S.basal_nodes[i].x * S.basal_nodes[i+1].y + S.apical_nodes[i].x * S.basal_nodes[i].y - S.apical_nodes[i].x * S.apical_nodes[i+1].y - S.apical_nodes[i+1].x * S.basal_nodes[i+1].y - S.basal_nodes[i+1].x * S.basal_nodes[i].y - S.basal_nodes[i].x * S.apical_nodes[i].y)) - A_0);        
        }
    E_total = E_cell_edge + E_cell_area;
    std::cout << "Energy of a Cell: " << E_total << endl;

    // output vertices as csv
    std::ofstream file("vertices.csv");
    file << "Apical_x, Apical_y, Basal_x, Basal_y\n";
    for (int i = 0; i < xa.size(); i++) {
        file << S.apical_nodes[i].x << "," << S.apical_nodes[i].y << ","
             << S.basal_nodes[i].x << "," << S.basal_nodes[i].y << "\n";
    }
    file.close();
    return 0;
}