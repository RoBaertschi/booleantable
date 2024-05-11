//
// Created by Robin on 09.05.2024.
//

#ifndef BOOLEANTABLE_TRUTHTABLE_H
#define BOOLEANTABLE_TRUTHTABLE_H

#include <vector>
#include <string>

class CTruthTable {
    size_t columns;
    size_t rows;
public:

    std::vector<std::string> inputVars;
    std::vector<bool> values;
    size_t valuesSize;

    explicit CTruthTable();
    explicit CTruthTable(const std::vector<std::string>& vars);

    bool getValue(size_t column, size_t row);
    inline void setValue(int column, int row, bool value);

    void debugPrint();

};



#endif //BOOLEANTABLE_TRUTHTABLE_H
