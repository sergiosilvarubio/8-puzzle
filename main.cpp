#include <iostream>
#include "grid.hpp"
#include "search_algorithms.hpp"

int main()
{
    SearchAlgorithms searchAlgorithms;

    // Estado inicial del puzzle (puedes cambiarlo para probar otras configuraciones)
    std::vector<std::vector<int>> start = {{1, 2, 3},
                                           {4, 5, 0},
                                           {7, 8, 6}};
    Grid startGrid(start, 3, 1, 2);

    // Estado objetivo del puzzle
    std::vector<std::vector<int>> goal[3];
    
    goal[0] = {{1, 2, 3},
               {0, 4, 5},
               {7, 8, 6}};  // Estado objetivo
    
    goal[1] = {{6, 8, 7},
               {5, 0, 4},
               {3, 2, 1}};

    goal[2] = {{1, 2, 3},
               {7, 4, 5},
               {8, 0, 6}};

    for (int i = 0; i < 3; i++)
    {
        Grid goalGrid(goal[i], 3, 2, 2);  // Crear el Grid de objetivo

        std::cout << "Estado inicial del puzzle:" << std::endl;
        startGrid.printBoard();

        std::cout << "Estado objetivo del puzzle: " << std::endl;
        goalGrid.printBoard();

        // Resolver el puzzle usando A*
        std::cout << "Ejecutando A* para resolver el puzzle..." << std::endl;
        searchAlgorithms.solveAStar(startGrid, goalGrid);  // Pasar el estado objetivo

        std::cout << std::endl;
    }

    

    return 0;
}
