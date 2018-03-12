/*
 * file: a-star.h
 * purpose: An implementation of the A-star path-finding algorithm for a situation
 *          where there is a balance between shortest path and least danger.
 */

#ifndef ASTAR_CPP_A_STAR_H
#define ASTAR_CPP_A_STAR_H

#include <array>
#include <cstdint>
#include <vector>

struct NODE;
struct EDGE;

struct NODE
{
public:

    explicit NODE(long int danger);
    ~NODE() = default;

    bool addEdge(EDGE & edge);

    long int my_danger;
    std::vector<EDGE> my_edges;
    long int my_average_adjacent_danger;

private:

    void calculateAdjacentDanger();
    NODE & getNeighbor(EDGE & edge);

};

struct EDGE
{
public:

    EDGE(int distance, NODE & first, NODE & second);
    ~EDGE() = default;

    long int my_distance;
    std::array<NODE, 2> my_nodes;
};


std::vector<NODE> & astar(NODE & start, NODE & goal, std::vector<NODE> & space);

#endif // ASTAR_CPP_A_STAR_H
