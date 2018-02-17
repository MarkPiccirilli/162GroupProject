#include "board.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

#include <iostream>

using namespace std;

Board::Board()
{
    grid = new Critter**[20];
    for(int i = 0; i < 20; i++)
    {
        grid[i] = new Critter*[20];
    }

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            grid[i][j] = nullptr;
        }
    }

    critterCount = 1;
}

//overload constructor to allow user to decide the size of the board
Board::Board(int rows, int columns) {
	//allocate memory
	grid = new Critter**[rows];
	for(int i=0; i<rows< i++)
		grid[i] = new Critter*[columns];
	
	//intitialize grid
	for(int i=0; i<rows; i++)
		for(j=0; j<columns; j++)
			grid[i][j] = NULL;
}
		

Board::~Board()
{
    for(int i = 0; i < 20; i++)
    {
        delete [] grid[i];
    }

    delete [] grid;
}

//getters
int getRows() {
	return rows;
}

int getColumns() {
	return columns;
}

//setters
void setRows(int rowsIn) {
	rows = rowsIn;
}

void setColumns() {
	columns = columnsIn;
}

void Board::printBoard()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] == nullptr)
            {
                cout << '.';
            }
            else if(grid[i][j]->getID() == 'O')
            {
                cout << 'O';
            }
			else if (grid[i][j]->getID() == 'X')
			{
				cout << 'X';
			}
        }
        cout << endl;
    }

    cout << endl;

}

Critter*** Board::getGrid()
{
    return grid;
}

void Board::checkAntMove()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] == nullptr)
            {

            }
            else if(grid[i][j]->getID() == 'O')
            {
                grid[i][j]->move(getGrid(), i, j);
            }
        }
    }
}

void Board::checkDoodleMove()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (grid[i][j] == nullptr)
			{

			}
			else if (grid[i][j]->getID() == 'X')
			{
				grid[i][j]->move(getGrid(), i, j);
			}
		}
	}
}

void Board::advanceAge()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] == nullptr)
            {

            }
            else //if(grid[i][j]->getID() == 'O')
            {
                grid[i][j]->setAge();
                grid[i][j]->setMoveHistory(false);
            }
        }
    }
}

void Board::checkAntBreed()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] == nullptr)
            {

            }
            else if(grid[i][j]->getID() == 'O')
            {
                grid[i][j]->breed(getGrid(), i, j);
            }
        }
    }
}


