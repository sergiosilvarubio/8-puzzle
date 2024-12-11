/*
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Estructura para representar un estado del puzzle
struct PuzzleState {
    vector<vector<int>> board;
    int x, y;  // Posición de la casilla vacía (0)
    int g, h;  // g: costo del camino, h: heurística estimada
    PuzzleState* parent; // Para rastrear el camino

    PuzzleState(vector<vector<int>> b, int empty_x, int empty_y, int g_cost, PuzzleState* p)
        : board(b), x(empty_x), y(empty_y), g(g_cost), h(0), parent(p) {}

    // Calcula la heurística usando la distancia de Manhattan
    void calculateHeuristic(const vector<vector<int>>& goal) {
        h = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int val = board[i][j];
                if (val != 0) {
                    // Busca la posición de la ficha en el estado objetivo
                    for (int x = 0; x < 3; ++x) {
                        for (int y = 0; y < 3; ++y) {
                            if (goal[x][y] == val) {
                                h += abs(i - x) + abs(j - y);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // Compara si el estado actual es igual al estado objetivo
    bool isGoal(const vector<vector<int>>& goal) const {
        return board == goal;
    }

    // Sobrecarga para comparar estados en la cola de prioridad (A*)
    bool operator<(const PuzzleState& other) const {
        return (g + h) > (other.g + other.h);  // Inverso porque priority_queue es max-heap por defecto
    }
};

// Movimientos posibles (arriba, abajo, izquierda, derecha)
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Verifica si una posición es válida
bool isValid(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

// Función para imprimir el estado del puzzle
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// A* para resolver el puzzle
void solvePuzzle(const vector<vector<int>>& start, const vector<vector<int>>& goal) {
    priority_queue<PuzzleState> openSet;
    unordered_map<string, bool> closedSet;

    // Encuentra la posición vacía (0) en el tablero inicial
    int empty_x, empty_y;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (start[i][j] == 0) {
                empty_x = i;
                empty_y = j;
                break;
            }
        }
    }

    // Estado inicial
    PuzzleState* startState = new PuzzleState(start, empty_x, empty_y, 0, nullptr);
    startState->calculateHeuristic(goal);
    openSet.push(*startState);

    while (!openSet.empty()) {
        PuzzleState current = openSet.top();
        openSet.pop();

        // Verifica si es el estado objetivo
        if (current.isGoal(goal)) {
            cout << "¡Puzzle resuelto!" << endl;
            vector<PuzzleState*> path;
            PuzzleState* trace = &current;
            while (trace) {
                path.push_back(trace);
                trace = trace->parent;
            }
            reverse(path.begin(), path.end());
            for (PuzzleState* state : path) {
                printBoard(state->board);
            }
            return;
        }

        // Genera los posibles movimientos
        for (auto& move : moves) {
            int new_x = current.x + move.first;
            int new_y = current.y + move.second;
            if (isValid(new_x, new_y)) {
                // Crea un nuevo estado intercambiando la casilla vacía con la ficha adyacente
                vector<vector<int>> newBoard = current.board;
                swap(newBoard[current.x][current.y], newBoard[new_x][new_y]);
                PuzzleState* newState = new PuzzleState(newBoard, new_x, new_y, current.g + 1, new PuzzleState(current));
                newState->calculateHeuristic(goal);

                // Asegura que no se revisite el mismo estado
                string boardStr = "";
                for (const auto& row : newBoard) {
                    for (int val : row) boardStr += to_string(val);
                }
                if (closedSet.find(boardStr) == closedSet.end()) {
                    openSet.push(*newState);
                    closedSet[boardStr] = true;
                }
            }
        }
    }

    cout << "No se encontró solución." << endl;
}

int maincito() {
    // Estado inicial del puzzle
    vector<vector<int>> start = {{1, 2, 3},
                                 {4, 0, 5},
                                 {6, 7, 8}};

    // Estado objetivo
    vector<vector<int>> goal = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 0}};

    // Resolver el puzzle
    solvePuzzle(start, goal);

    return 0;
}
*/