// Since adjacent cells share vertices, here is a code that shows how to create 
// a vector of cells with vertices and how to loop over the cells and vertices.

#include <vector>
#include <iostream>

using namespace std;

class Vertices {
public:
    double x, y;
    // Constructor initializing the vertices 
    Vertices(double x1, double y1){
        x = x1;
        y = y1;
    }
};

class Cell {
public:
    // Vector of vertices is used instead of array because it gives freedom 
    // to add or remove vertices without changing the size of the array

    // Vertices of the cell
    vector<Vertices> nodes; 
    // Constructor initializing the vertices of the object
    Cell(const vector<Vertices>& input_nodes) {
        nodes = input_nodes;
    }
};

int main() {
    // vector of cells with vertices
    vector<Cell> cells = {
        Cell({Vertices(0,0), Vertices(2,0), Vertices(2, 2), Vertices(0,2)}), // Cell 1
        Cell({Vertices(2,0), Vertices(4,0), Vertices(4,2), Vertices(2,2)}), // Cell 2
        Cell({Vertices(4,0), Vertices(6,0), Vertices(6,2), Vertices(4,2)}), // Cell 3
        Cell({Vertices(6,0), Vertices(8,0), Vertices(8,2), Vertices(6,2)}), // Cell 4
        Cell({Vertices(8,0), Vertices(10,0), Vertices(10,2), Vertices(8,2)}) // Cell 5
    };

    // Loop over the cells
    for (size_t i = 0; i < cells.size(); i++) {
        cout << "Cell " << i + 1 << " has the following vertices:"<< endl;
        // Loop over the vertices of the cell
        for (const Vertices& vertex : cells[i].nodes) {
            cout << "(" << vertex.x << ", " << vertex.y << ")"<< endl;
        }
    }
    // usually when there is force on the cell, the vertices will change
    // Here since we do not have the force or energy terms yet, 
    // we will just insert a new vertex to the second cell
    cells[2].nodes.insert(cells[2].nodes.begin() + 3, Vertices(5,3));
    cout << "New vertex(5,3)was inserted and now Cell 3 has the following vertices:"<< endl;
    for (const Vertices& vertex : cells[2].nodes) {
        cout << "(" << vertex.x << ", " << vertex.y << ")"<< endl;
    }
    return 0;
}
