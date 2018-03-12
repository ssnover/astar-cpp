//
// Created by ssnover on 3/11/18.
//

#include "a-star.h"
#include <map>

NODE::NODE(long int danger) : my_danger(danger)
{
    // Empty constructor
}

bool NODE::addEdge(EDGE & edge)
{
    this->my_edges.emplace_back(edge);

    // Recalculate adjacent danger
    calculateAdjacentDanger();

    return true;
}

void NODE::calculateAdjacentDanger()
{
    long int total_adjacent_danger(0);

    if (this->my_edges.empty())
    {
        this->my_average_adjacent_danger = 0;
    }
    else
    {
        for (auto & iter_edges : this->my_edges)
        {
            for (auto & iter_nodes : iter_edges.my_nodes)
            {
                if (&iter_nodes == this)
                {
                    continue;
                }
                else
                {
                    total_adjacent_danger += iter_nodes.my_danger;
                }
            }
        }

        this->my_average_adjacent_danger =
            total_adjacent_danger / this->my_edges.size();
    }
}

NODE & NODE::getNeighbor(EDGE & edge)
{
    for (auto & iter : edge.my_nodes)
    {
        if (this == &iter)
        {
            continue;
        }
        else
        {
            return iter;
        }
    }
}

EDGE::EDGE(int distance, NODE & first, NODE & second)
    : my_distance(distance), my_nodes({first, second})
{
    // Empty constructor
}

std::vector<NODE> & astar(NODE & start, NODE & goal, std::vector<NODE> & space)
{
    std::vector<NODE> closed_set;
    std::vector<NODE> open_set = {start};

    std::map<NODE, int> gScore;
    gScore[start] = 0;
}
