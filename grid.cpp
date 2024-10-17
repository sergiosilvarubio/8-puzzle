#include <iostream>

#include "grid.hpp"

Grid::Grid(std::vector<std::vector<int>> grid, int size, int empty_x, int empty_y)
            : _grid{grid}, _size(size), _x(empty_x), _y(empty_y) {}
Grid::~Grid() {}

void Grid::printBoard()
{
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++)
            (_grid[i][j] == 0) ? std::cout << "  " : std::cout << _grid[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Grid::isSolved()
{
    int val = 1;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (i == _size - 1 && j == _size - 1) {  // Última posición
                if (_grid[i][j] != 0) return false;  // Posición vacía
            } else {
                if (_grid[i][j] != val++) return false;
            }
        }
    }
    return true;
}

// Función para mover la casilla vacía
bool Grid::move(int x, int y)
{
    if (x < 0 || x >= _size || y < 0 || y >= _size) {
        std::cout << "Movimiento inválido." << std::endl;
        return false;
    }
    if (abs(_x - x) + abs(_y - y) == 1) {  // Solo se puede mover si la posición es adyacente a la casilla vacía
        std::swap(_grid[_x][_y], _grid[x][y]);
        _x = x, _y = y;
        return true;
    } else {
        std::cout << "Movimiento no permitido." << std::endl;
        return false;
    }
}


// Función para que un humano realice un movimiento
void Grid::humanMove()
{
    int x, y;
    std::cout << "Ingrese fila (0 - " << _size-1 << "): ";
    std::cin >> x;
    std::cout << "Ingrese columna (0 - " << _size-1 << "): ";
    std::cin >> y;
    if (!move(x, y)) {
        std::cout << "Intenta de nuevo." << std::endl;
        humanMove();
    }
}