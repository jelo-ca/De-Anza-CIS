#pragma once

#include "DirectedGraph.h"

class AdjacencyMatrixGraph : public DirectedGraph {
protected:
    std::vector<Vertex*> vertices;

    // If matrixRows[X][Y] is true, then an edge exists from vertices[X] to
    // vertices[Y]
    std::vector<std::vector<bool>> matrixRows;

    void AddMatrixRowColumn() {
        if (matrixRows.size() > 0) {
            // First add a column by pushing false to the back of each existing row
            for (auto& row : matrixRows) {
                row.push_back(false);
            }

            // Make a new row with the same size as other rows and all entries
            // assigned with false
            std::vector<bool> newRow;
            newRow.resize(matrixRows[0].size(), false);

            // Add the new row
            matrixRows.push_back(newRow);
        }
        else {
            // Special case if matrixRows is empty
            std::vector<bool> row = { false };
            matrixRows.push_back(row);
        }
    }

    // Returns the index of the vertex in the vertices vector, or -1 if the
    // vertex is not in the vector
    int IndexOf(Vertex* vertex) {
        for (int i = 0; i < (int)vertices.size(); i++) {
            if (vertex == vertices[i]) {
                return i;
            }
        }
        return -1;
    }

public:
    virtual ~AdjacencyMatrixGraph() {
        for (Vertex* vertex : vertices) {
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

        // Create and add the vertex
        Vertex* vertex = new Vertex(newVertexLabel);
        vertices.push_back(vertex);

        // Adding a vertex adds a row and column to the matrix
        AddMatrixRowColumn();

        return vertex;
    }

    // Adds a directed edge from the first to the second vertex. If the edge
    // already exists in the graph, no change is made and false is returned.
    // Otherwise the new edge is added and true is returned.
    virtual bool AddDirectedEdge(Vertex* fromVertex, Vertex* toVertex) override {
        if (HasEdge(fromVertex, toVertex)) {
            return false;
        }

        // Assign the matrix entry
        int fromVertexIndex = IndexOf(fromVertex);
        int toVertexIndex = IndexOf(toVertex);
        matrixRows[fromVertexIndex][toVertexIndex] = true;

        return true;
    }

    // Returns a vector of edges with the specified fromVertex.
    virtual std::vector<Edge> GetEdgesFrom(Vertex* fromVertex) override {
        std::vector<Edge> result;
        int fromVertexIndex = IndexOf(fromVertex);
        if (fromVertexIndex >= 0) {
            auto& row = matrixRows[fromVertexIndex];
            for (int j = 0; j < (int)row.size(); j++) {
                Vertex* toVertex = vertices[j];
                if (row[j]) {
                    result.push_back(Edge(fromVertex, toVertex));
                }
            }
        }
        return result;
    }

    // Returns a vector of edges with the specified toVertex.
    virtual std::vector<Edge> GetEdgesTo(Vertex* toVertex) override {
        std::vector<Edge> result;
        int toVertexIndex = IndexOf(toVertex);
        if (toVertexIndex >= 0) {
            // toVertexIndex is the column index. Iterate through rows to find
            // column entries assigned with true
            for (int rowIndex = 0; rowIndex < (int)matrixRows.size(); rowIndex++) {
                if (matrixRows[rowIndex][toVertexIndex]) {
                    Vertex* fromVertex = vertices[rowIndex];
                    result.push_back(Edge(fromVertex, toVertex));
                }
            }
        }
        return result;
    }

    // Returns a vertex with a matching label, or nullptr if no such vertex
    // exists
    virtual Vertex* GetVertex(std::string vertexLabel) override {
        for (Vertex* vertex : vertices) {
            if (vertex->GetLabel() == vertexLabel) {
                return vertex;
            }
        }
        return nullptr;
    }

    // Returns true if this graph has an edge from fromVertex to toVertex
    virtual bool HasEdge(Vertex* fromVertex, Vertex* toVertex) override {
        int fromVertexIndex = IndexOf(fromVertex);
        int toVertexIndex = IndexOf(toVertex);
        if (fromVertexIndex >= 0 && toVertexIndex >= 0) {
            return matrixRows[fromVertexIndex][toVertexIndex];
        }
        return false;
    }
};


