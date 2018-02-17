#include <iostream>

#include "board.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
#include "inVal.hpp"
#include <time.h>

using std::cin;
using std::cout;
using std:: endl;

int main()
{
    cout << "We did the extra credit!!!!!" << endl << endl;

    srand(time(NULL)); //im not sure what this is doing

    //prompt user for Board size
    cout << "Please enter number of rows in grid: ";
    int rows = inVal(999, 999, 0, 0);
    cout << "Please enter number of columns in grid: ";
    int columns = inVal(999, 999, 0, 0);
    //overload constructor that I dont think is created yeat
    Board b1(rows, columns);
    //print board
    b1.printBoard();

    Critter*** g1 = b1.getGrid();

    //ompt user for number of ants
    cout << "Please enter the starting number of Ants: ";
    int numAnts = inVal(200, 200, 50, 50);
    for(int i=0; i<numAnts; i++) {
       Critter c1 = new Ant();
       int r, c;
       do {
          r = rand % b1.getRows() + 1;
          c = rand % b1.getColumns() + 1;
       } while(g1[r][c] != NULL)
       g1[r][c] = c1;
    }

    //promput user for number of doodle bugs
    cout << "Please enter number of doodlebugs: ";
    int numDoodle =inVal(20, 20, 2, 2);
    for(int i=0; i<numDoodle; i++) {
       Critter* c2 = new Doodle();
       int r, c;
       do {
          r = rand % b1.getRows() + 1;
          c = rand % b1.getColumns() + 1;
       } while(g1[r][c] != NULL)
       g1[r][c] = c1;
    }

    //prompt user for number steps
    cout << "Please enter the number of steps in the simuation: ";
    int steps = inVal(99999, 999999, 1, 1);

    for(int i = 0; i < steps; i++)
    {
        b1.checkDoodleMove();
        b1.checkAntMove();
        b1.checkAntBreed();
        b1.advanceAge();
        b1.printBoard();
    }

    return 0;
}
