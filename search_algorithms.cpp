#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "search_algorithms.hpp"
#include "grid.hpp"

struct Node
{
    Grid state;
    int cost; // g(n)
    int priority; // f(n)

    bool operator < (const Node& other) const
    {
        return priority > other.priority;
    }
};

void SearchAlgorithms::solveAStar(Grid start, Grid goal)
{
    std::priority_queue<Node> frontier;
    std::unordered_map<std::string, int> cost_so_far;
    std::unordered_set<std::string> explored;

    // Insertar el estado inicial en la frontera
    frontier.push({start, 0, start.heuristic()});
    cost_so_far[start.serialize()] = 0;

    while(!frontier.empty())
    {
        Node current = frontier.top();
        frontier.pop();

        // Si el estado actual es el objetivo, se encontró la solución
        if (current.state.serialize() == goal.serialize())  // Comparar con el estado objetivo
        {
            std::cout << "La solución encontrada tiene costo: " << current.cost << std::endl;
            return;
        }

        if (explored.count(current.state.serialize()))
            continue;

        explored.insert(current.state.serialize());

        // Explorar los vecinos
        for (const Grid& neighbor : current.state.neighbors())
        {
            int new_cost = current.cost + 1;

            if ((!cost_so_far.count(neighbor.serialize())) || new_cost < cost_so_far[neighbor.serialize()])
            {
                cost_so_far[neighbor.serialize()] = new_cost;
                int priority = new_cost + neighbor.heuristic(); // f(n) = g(n) + h(n)
                frontier.push({neighbor, new_cost, priority});
            }
        }
    }

    std::cout << "No se encontró solución." << std::endl;
}