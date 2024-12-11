#include <array>
#include <vector>
#include <iostream>
#include <utility>

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

int Grid::heuristic() const 
{
    int h = 0;

    for (int i = 0; i < _size; ++i)
    {
        for (int j = 0; j < _size; ++j)
        {
            int value = _grid[i][j];
            
            if (value != 0)
            {
                int target_x = (value - 1) / _size;
                int target_y = (value - 1) % _size;
                h += abs(i - target_x) + abs(j - target_y);
            }
        }   
    }    

    return h;
}

std::vector<Grid> Grid::neighbors() const 
{
    std::vector<Grid> result;

    // Usar std::vector para evitar problemas de inicialización
    const std::vector<std::pair<int, int>> deltas = {
        { -1, 0 },
        { 1, 0 },
        { 0, -1 },
        { 0, 1 }
    };

    for (const auto& delta : deltas) 
    {
        int new_x = _x + delta.first;
        int new_y = _y + delta.second;

        if (new_x >= 0 && new_x < _size && new_y >= 0 && new_y < _size) 
        {
            Grid neighbor = *this; // Copia el estado actual
            if (neighbor.move(new_x, new_y)) 
                result.push_back(neighbor);
        }
    }

    return result;
}

std::string Grid::serialize() const 
{
    std::string serialized;
    
    for (const auto& row : _grid) 
        for (int cell : row) 
            serialized += std::to_string(cell) + ",";
    
    return serialized;
}

bool Grid::operator < (const Grid& other) const 
{
    return this->heuristic() < other.heuristic();
}
