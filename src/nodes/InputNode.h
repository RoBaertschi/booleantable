//
// Created by Robin on 09.05.2024.
//

#ifndef BOOLEANTABLE_INPUTNODE_H
#define BOOLEANTABLE_INPUTNODE_H

#include <ImNodeFlow.h>
#include "../TruthTable.h"

class CInputNode : public ImFlow::BaseNode {
    std::shared_ptr<CTruthTable> table;
    size_t row;
public:
    explicit CInputNode(std::shared_ptr<CTruthTable> truthTable, size_t row);


};


#endif //BOOLEANTABLE_INPUTNODE_H
