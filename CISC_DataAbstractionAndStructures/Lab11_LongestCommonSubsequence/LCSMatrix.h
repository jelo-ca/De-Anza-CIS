#pragma once

#include <string>
#include <unordered_set>
#include <vector>

struct LCSMatrixEntry {
    int value;
    bool match;
    std::unordered_set<std::string> lcsSet;

    // Constructs a default entry that has a value=0, match=false, and an empty
    // lcsSet
    LCSMatrixEntry() {
        value = 0;
        match = false;
    }

    LCSMatrixEntry(const LCSMatrixEntry& toCopy) {
        value = toCopy.value;
        match = toCopy.match;
        lcsSet = toCopy.lcsSet;
    }

    // Utility function that returns the LCSMatrixEntry with the greater value.
    // If the two entries have the same value, then a new entry is returned with
    // the shared value and a union of the two LCS sets.
    static LCSMatrixEntry Max(LCSMatrixEntry entry1, LCSMatrixEntry entry2) {
        if (entry1.value == entry2.value) {
            // Copy entry1's set
            std::unordered_set<std::string> unionSet(entry1.lcsSet);

            // Add each string from entry2's set
            for (auto str : entry2.lcsSet) {
                unionSet.insert(str);
            }

            LCSMatrixEntry result;
            result.value = entry1.value;
            result.lcsSet = unionSet;
            return result;
        }
        else if (entry1.value >= entry2.value) {
            return entry1;
        }
        return entry2;
    }
};

class LCSMatrix {
private:
    int rowCount;
    int columnCount;
    std::vector<LCSMatrixEntry> data;

    // Returns a copy of the matrix entry at the specified row and column
    // indices, or the default entry if either index is out of bounds.
    LCSMatrixEntry Get(int rowIndex, int columnIndex) {
        // Check if either index is out of bounds
        if (rowIndex < 0 || rowIndex >= rowCount ||
            columnIndex < 0 || columnIndex >= columnCount) {
            return LCSMatrixEntry();
        }
        return data[rowIndex * columnCount + columnIndex];
    }

public:
    LCSMatrix(std::string& str1, std::string& str2) {
        this->rowCount = (int)str1.length();
        this->columnCount = (int)str2.length();

        // Allocate matrix entries
        data.resize(rowCount * columnCount, LCSMatrixEntry());

        // Populate the matrix entries
        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < columnCount; col++) {
                // Get a reference to the current entry
                LCSMatrixEntry& currentEntry = data[row * columnCount + col];

                // Check if the characters match
                if (str1[row] == str2[col]) {
                    // Get the entry in the cell that's up and to the left
                    LCSMatrixEntry upLeft = Get(row - 1, col - 1);

                    // Special case if upper-left's LCS set is empty
                    if (0 == upLeft.lcsSet.size()) {
                        currentEntry.lcsSet.insert(std::string("") + str1[row]);
                    }
                    else {
                        // New entry's LCS set is the upper-left's LCS set, but with
                        // the matching character concatenated onto each entry
                        for (auto lcs : upLeft.lcsSet) {
                            currentEntry.lcsSet.insert(lcs + str1[row]);
                        }
                    }

                    // Set the entry at (row, col)
                    currentEntry.value = 1 + upLeft.value;
                    currentEntry.match = true;
                }
                else {
                    // The current entry does not represent a character match
                    currentEntry.match = false;

                    // Get maximum between entry to the left and entry above
                    LCSMatrixEntry maxEntry = LCSMatrixEntry::Max(
                        Get(row - 1, col), Get(row, col - 1));

                    // Copy maxEntry's value and lcs to currentEntry
                    currentEntry.value = maxEntry.value;
                    currentEntry.lcsSet = maxEntry.lcsSet;
                }
            }
        }
    }

    // Returns the number of columns in the matrix, which also equals the length
    // of the second string passed to the constructor.
    int GetColumnCount() {
        return columnCount;
    }

    // Returns the matrix entry at the specified row and column indices, or 0 if
    // either index is out of bounds.
    int GetEntry(int rowIndex, int columnIndex) {
        // Check if either index is out of bounds
        if (rowIndex < 0 || rowIndex >= rowCount ||
            columnIndex < 0 || columnIndex >= columnCount) {
            return 0;
        }

        return data[rowIndex * columnCount + columnIndex].value;
    }

    // Returns the number of rows in the matrix, which also equals the length
    // of the first string passed to the constructor.
    int GetRowCount() {
        return rowCount;
    }

    // Returns the set of distinct, longest common subsequences between the two
    // strings that were passed to the constructor.
    std::unordered_set<std::string> GetLongestCommonSubsequences() {
        // Special case for empty vector
        if (0 == data.size()) {
            return std::unordered_set<std::string>();
        }

        // Last matrix entry has the LCS set
        return data[data.size() - 1].lcsSet;
    }
};


