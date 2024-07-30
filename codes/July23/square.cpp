// adding boundary condition (failed edition)
// this code is incomplete
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
    Vertices(double x1, double y1) 
    {
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
    vector<Cell> cells;
    int N, M;

    // constructor
    // N is the number of cells horizontally and M is the number vertically.
    System(int N, int M, double l, double h) : N(N), M(M) 
    {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // vertex initialization
                apical_nodes.push_back(Vertices(j * l / (N - 1), i * h));
                basal_nodes.push_back(Vertices(j * l / (N - 1), i * h - h));
                // cell initialization
                cells.push_back(Cell());
            }
        }
    }

    // boundary condition
    int modulateBoundary(int i, int l) {
        if (i >= l) {
            return i % l;
        } else if (i < 0) {
            return (i + l) % l;
        } else {
            return i;
        }
    }
    // // boundary condition
    // int modulateBoundary(int i, int l) {
    //     if (i == N + 1) {
    //         return ((i + 1) / N) % N - l;
    //     } else if (i == -1) {
    //         return ((i + 1) / N) % N + l;
    //     } else {
    //         return ((i + 1) / N) % N;
    //     }
    // }
};



int main() {   
    // we use three variables l, N, and h to generate the initial coordinates
    // l is the total length of the tissue, N is the number of cells horizontally, M is the number of cells vertically, and h is the height of the cell
    double l = 10, h = 1;
    int N = 10, M = 4; 

    System S(N, M, l, h);

    // Uncomment to change the coordinates
    S.apical_nodes[15].y = 7;
    S.basal_nodes[12].y = -9;
    S.basal_nodes[0].y = -9;
    // tension (change as required)
    double alpha_a = 1, alpha_b = 1, alpha_l = 1;
    double E_cell_edge = 0, E_cell_area = 0, E_total = 0;
    double beta = 1, A_0 = 1;
    int n = S.apical_nodes.size();
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
    std::ofstream file("vertices_square.csv");
    file << "Apical_x, Apical_y, Basal_x, Basal_y\n";
    for (int i = 0; i < S.apical_nodes.size(); i++) {
        file << S.apical_nodes[i].x << "," << S.apical_nodes[i].y << ","
             << S.basal_nodes[i].x << "," << S.basal_nodes[i].y << "\n";
    }
    file.close();
    return 0;
}