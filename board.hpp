#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include "critter.hpp"

class Board
{
    private:
        Critter*** grid;
        int critterCount;
	int rows;
	int columns;

    public:
        Board();
	Board(int, int);
        ~Board();
	int getRows();
	int getColumns();
	void setRows(int );
	void setColumns(int );
        Board getBoard();
        Critter*** getGrid();
        void printBoard();
        void checkAntMove();
		void checkDoodleMove();
        void advanceAge();
        void checkAntBreed();

};

#endif // BOARD_HPP_INCLUDED
