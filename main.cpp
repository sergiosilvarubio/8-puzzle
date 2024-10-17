#include <iostream>

#include "grid.hpp"
#include "search_algorithms.hpp"

int main()
{
    SearchAlgorithms searchAlgorithms;
    // Pruebas: Estados iniciales del puzzle
    /*
    std::vector<std::vector<int>> start = {{1, 2, 3},
                                           {4, 0, 5},
                                           {6, 7, 8}};
    Grid grid(start, 3, 1, 1);
    */
    // Fácil
    std::vector<std::vector<int>> start = {{1, 2, 3},
                                           {4, 5, 0},
                                           {7, 8, 6}};
    Grid grid(start, 3, 1, 2);

    std::cout << "Estado inicial del puzzle:" << std::endl;
    grid.printBoard();

    while (!grid.isSolved()) {
        grid.humanMove();
        grid.printBoard();
    }
    std::cout << "Juego Terminado" << std::endl;

    return 0;
}