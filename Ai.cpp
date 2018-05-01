#include "Ai.h"
#include <iostream>
using namespace std;

const bool operator == (GridLocation a, GridLocation b) { // x & y's in header
    return a.x == b.x && a.y == b.y;
}

const bool operator != (GridLocation a, GridLocation b) {
    return !(a == b);
}

const bool operator < (GridLocation a, GridLocation b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}

void add_rect(SquareGrid& grid, int x1, int y1, int x2, int y2) {
    for (int x = x1; x < x2; ++x) {
        for (int y = y1; y < y2; ++y) {
            grid.walls.insert(GridLocation{x, y});
        }
    }
}

SquareGrid make_diagram1() {
    SquareGrid grid(30, 15);
    add_rect(grid, 3, 3, 5, 12);
    add_rect(grid, 13, 4, 15, 15);
    add_rect(grid, 21, 0, 23, 7);
    add_rect(grid, 23, 5, 26, 7);
    return grid;
}

inline double heuristic(GridLocation a, GridLocation b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

template<typename Location, typename Graph>
void a_star_search
(Graph graph,
 Location start,
 Location goal,
 std::map<Location, Location>& came_from,
 std::map<Location, double>& cost_so_far) {
    PriorityQueue<Location, double> frontier;
    frontier.put(start, 0);

    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        Location current = frontier.get();

        if (current == goal) {
            break;
        }

        for (Location next : graph.neighbors(current)) {
            double new_cost = cost_so_far[current] + graph.cost(current, next);
            if (cost_so_far.find(next) == cost_so_far.end()
                || new_cost < cost_so_far[next]) {
                cost_so_far[next] = new_cost;
                double priority = new_cost + heuristic(next, goal);
                frontier.put(next, priority);
                came_from[next] = current;
            }
        }
    }
}

template<class Graph>
void draw_grid(const Graph& graph, int field_width,
               std::map<GridLocation, double>* distances=nullptr,
               std::map<GridLocation, GridLocation>* point_to=nullptr,
               std::vector<GridLocation>* path=nullptr) {
    for (int y = 0; y != graph.height; ++y) {
        for (int x = 0; x != graph.width; ++x) {
            GridLocation id {x, y};
            std::cout << std::left << std::setw(field_width);
            if (graph.walls.find(id) != graph.walls.end()) {
                std::cout << std::string(field_width, '#');
            } else if (point_to != nullptr && point_to->count(id)) {
                GridLocation next = (*point_to)[id];
                if (next.x == x + 1) { std::cout << "> "; }
                else if (next.x == x - 1) { std::cout << "< "; }
                else if (next.y == y + 1) { std::cout << "v "; }
                else if (next.y == y - 1) { std::cout << "^ "; }
                else { std::cout << "* "; }
            } else if (distances != nullptr && distances->count(id)) {
                std::cout << (*distances)[id];
            } else if (path != nullptr && find(path->begin(), path->end(), id) != path->end()) {
                std::cout << '@';
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}

template<typename Location>
std::vector<Location> reconstruct_path(
                                       Location start, Location goal,
                                       std::map<Location, Location> came_from
                                       ) {
    std::vector<Location> path;
    Location current = goal;
    while (current != start) {
        path.push_back(current);
        current = came_from[current];
    }
    path.push_back(start); // optional
    std::reverse(path.begin(), path.end());
    return path;
}

template<typename Location>
Ai::Ai(MapGen* map, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            switch(map->getTile(i,j)) {
                case '#': //wall
                    Wall.set<Location>::insert(GridLocation(i,j));
                  //  Wall.set::insert(i,j);
                    break;
                case '.': //floor
                    Floor.set<Location>::insert(GridLocation(i,j));
                    break;
        }
    }


}
}
