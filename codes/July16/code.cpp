// code to calculate energy - changed the initial coordinates
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
    // we use three variables l, N, and h to generate the initial coordinates
    // l is the total length of the tissue, N is the number of vertices, and h is the height of the cell

    vector<double> xa, ya, xb, yb;
    double l = 2, h = 1;
    int N = 3;
    for (int i = 0; i < N; i++)
    {
        xa.push_back(i * l / (N-1));
        ya.push_back(h);
        xb.push_back(i * l / (N-1));
        yb.push_back(0);
    }

    System S(xa,ya,xb,yb);

    // uncomment to change third cell apical coordinate
    S.apical_nodes[1].y = 7;
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