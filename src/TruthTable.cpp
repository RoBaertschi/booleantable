//
// Created by Robin on 09.05.2024.
//

#include <cmath>
#include <iostream>
#include "TruthTable.h"
#include "Logging.h"

CTruthTable::CTruthTable(const std::vector<std::string>& vars) : inputVars(vars) {

    columns = vars.size();
    rows = 1 << vars.size();

    if (!vars.empty()) {
        valuesSize = rows*columns;
        values.resize(valuesSize);

        for (int i = 0; i < valuesSize; ++i) {
            values[i] = false;
        }
    } else {
        valuesSize = 0;
        return;
    }



    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            values[j + (i * columns)] = ((i >> j) & 1) == 0;
        }
    }

/*
    for (int x = 0; x < columns; ++x) {
        std::cout << vars[x] << "|";
        for (int y = 0; y < rows; ++y) {
            std::cout << getValue(x, y);
        }
        std::cout << "|\n";
    }
*/


}


bool CTruthTable::getValue(size_t column, size_t row) {
    return values[column + (row * columns)];
}

inline void CTruthTable::setValue(int column, int row, bool value) {
    values[column + (row * columns)] = value;
}

void CTruthTable::debugPrint() {

    for (int c = 0; c < columns; ++c) {
        std::cout << "|" << inputVars[c];
    }
    std::cout << "|\n";

    for (int s = 0; s < columns*rows; ++s) {
        std::cout<<"|"<< values[s];
        if ((s + 1)  % columns == 0) {
            std::cout << "|";
            std::cout << "\n";
        }
    }
}

CTruthTable::CTruthTable() : CTruthTable(std::vector<std::string>()) {}

