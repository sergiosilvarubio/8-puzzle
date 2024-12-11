#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

class Grid
{
    private:
        std::vector<std::vector<int>> _grid;
        int _size;
        int _x, _y;  // Posición de la casilla vacía (0)

        bool move(int x, int y);

    public:
        Grid(std::vector<std::vector<int>> grid, int size, int empty_x, int empty_y);  // Constructor prototype
        ~Grid(); // Destructor prototype

        void printBoard();
        bool isSolved();
        void humanMove();

        int heuristic() const;
        std::vector<Grid> neighbors() const;
        std::string serialize() const;

        bool operator < (const Grid& other) const;
};

#endif //GRID_HPP
