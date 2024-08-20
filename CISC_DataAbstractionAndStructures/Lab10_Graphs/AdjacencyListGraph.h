#pragma once

#include "DirectedGraph.h"
#include "AdjacencyListVertex.h"

class AdjacencyListGraph : public DirectedGraph {
protected:
    std::vector<AdjacencyListVertex*> vertices;

public:
    virtual ~AdjacencyListGraph() {
        for (AdjacencyListVertex* vertex : vertices) {
            delete vertex;
        }
    }

    // Creates and adds a new vertex to the graph, provided a vertex with the
    // same label doesn't already exist in the graph. Returns the new vertex on
    // success, nullptr on failure.
    virtual Vertex* AddVertex(std::string newVertexLabel) override {
        // Return nullptr if a vertex with the label already exists
        if (GetVertex(newVertexLabel)) {
            return nullptr;
        }

        // Create, add, and return the vertex
        AdjacencyListVertex* vertex = new AdjacencyListVertex(newVertexLabel);
        vertices.push_back(vertex);
        return vertex;
    }

    // Adds a directed edge from the first to the second vertex. If the edge
    // already exists in the graph, no change is made and false is returned.
    // Otherwise the new edge is added and true is returned.
    virtual bool AddDirectedEdge(Vertex* fromVertex, Vertex* toVertex) override {
        if (HasEdge(fromVertex, toVertex)) {
            return false;
        }

        ((AdjacencyListVertex*)fromVertex)->adjacent.push_back(toVertex);
        return true;
    }

    // Returns a vector of edges with the specified fromVertex.
    virtual std::vector<Edge> GetEdgesFrom(Vertex* fromVertex) override {
        std::vector<Edge> result;
        for (Vertex* toVertex : ((AdjacencyListVertex*)fromVertex)->adjacent) {
            result.push_back(Edge(fromVertex, toVertex));
        }
        return result;
    }

    // Returns a vector of edges with the specified toVertex.
    virtual std::vector<Edge> GetEdgesTo(Vertex* toVertex) override {
        std::vector<Edge> result;

        // Iterate through all edges in the graph, adding each that has toVertex
        // as the to-vertex
        for (AdjacencyListVertex* fromVertex : vertices) {
            for (Vertex* candidate : fromVertex->adjacent) {
                if (candidate == toVertex) {
                    result.push_back(Edge(fromVertex, toVertex));
                }
            }
        }
        return result;
    }

    // Returns a vertex with a matching label, or nullptr if no such vertex
    // exists
    virtual Vertex* GetVertex(std::string vertexLabel) override {
        // Iterate through all vertices to see if a matching label exists
        for (AdjacencyListVertex* vertex : vertices) {
            if (vertex->GetLabel() == vertexLabel) {
                return vertex;
            }
        }
        return nullptr;
    }

    // Returns true if this graph has an edge from fromVertex to toVertex
    virtual bool HasEdge(Vertex* fromVertex, Vertex* toVertex) override {
        // Iterate through fromVertex's adjacent vertices
        for (Vertex* candidate : ((AdjacencyListVertex*)fromVertex)->adjacent) {
            if (candidate == toVertex) {
                return true;
            }
        }
        return false;
    }
};


