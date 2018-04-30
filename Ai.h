#ifndef AI_h
#define AI_h
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <array>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstdlib>

#include "MapGen.h"
#include "Board.h"

//fix this & cpp file

class GridLocation {
public:
    int x, y;
    GridLocation(int x, int y);
};


struct SquareGrid {
    static std::array<GridLocation, 4> DIRS;

    int width, height;
    std::set<GridLocation> walls;

    SquareGrid(int width_, int height_)
    : width(width_), height(height_) {}

    bool in_bounds(GridLocation id) const {
        return 0 <= id.x && id.x < width
        && 0 <= id.y && id.y < height;
    }

    bool passable(GridLocation id) const {
        return walls.find(id) == walls.end();
    }

    std::vector<GridLocation> neighbors(GridLocation id) const {
        std::vector<GridLocation> results;

        for (GridLocation dir : DIRS) {
            GridLocation next{id.x + dir.x, id.y + dir.y};
            if (in_bounds(next) && passable(next)) {
                results.push_back(next);
            }
        }

        if ((id.x + id.y) % 2 == 0) {
            // aesthetic improvement on square grids
            std::reverse(results.begin(), results.end());
        }

        return results;
    }
};


struct GridWithWeights: SquareGrid {
    std::set<GridLocation> forests;
    GridWithWeights(int w, int h): SquareGrid(w, h) {}
    double cost(GridLocation from_node, GridLocation to_node) const {
        return forests.find(to_node) != forests.end()? 5 : 1;
    }
};



std::basic_iostream<char>::basic_ostream& operator<<(std::basic_iostream<char>::basic_ostream& out, const GridLocation& loc) {
    out << '(' << loc.x << ',' << loc.y << ')';
    return out;
}


template<typename T, typename priority_t>
struct PriorityQueue {
    typedef std::pair<priority_t, T> PQElement;
    std::priority_queue<PQElement, std::vector<PQElement>,
    std::greater<PQElement>> elements;

    inline bool empty() const {
        return elements.empty();
    }

    inline void put(T item, priority_t priority) {
        elements.emplace(priority, item);
    }

    T get() {
        T best_item = elements.top().second;
        elements.pop();
        return best_item;
    }
};

/*
GridWithWeights make_diagram4() {
    GridWithWeights grid(10, 10);
    add_rect(grid, 1, 7, 4, 9);
    typedef GridLocation L;
    grid.forests = std::set<GridLocation> {
        L{3, 4}, L{3, 5}, L{4, 1}, L{4, 2},
        L{4, 3}, L{4, 4}, L{4, 5}, L{4, 6},
        L{4, 7}, L{4, 8}, L{5, 1}, L{5, 2},
        L{5, 3}, L{5, 4}, L{5, 5}, L{5, 6},
        L{5, 7}, L{5, 8}, L{6, 2}, L{6, 3},
        L{6, 4}, L{6, 5}, L{6, 6}, L{6, 7},
        L{7, 3}, L{7, 4}, L{7, 5}
    };
    return grid;
}
*/


class Ai {

public:
    Ai(MapGen* map, int size);

    friend const bool operator == (GridLocation a, GridLocation b);

    friend const bool operator != (GridLocation a, GridLocation b);

    friend const bool operator < (GridLocation a, GridLocation b);

    void add_rect(SquareGrid& grid, int x1, int y1, int x2, int y2);

    //int location(int x, int y);

    template<class Graph>
    void draw_grid(const Graph& graph, int field_width,
                   std::map<GridLocation, double>* distances=nullptr,
                   std::map<GridLocation, GridLocation>* point_to=nullptr,
                   std::vector<GridLocation>* path=nullptr);

    SquareGrid make_diagram1();

    inline double heuristic(GridLocation a, GridLocation b);

    template<typename Location, typename Graph>
    void a_star_search
    (Graph graph,
     Location start,
     Location goal,
     std::map<Location, Location>& came_from,
     std::map<Location, double>& cost_so_far);

    template<typename Location>
    std::vector<Location> reconstruct_path(
                                           Location start, Location goal,
                                           std::map<Location, Location> came_from
                                           );




};
#endif
