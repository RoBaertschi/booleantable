//
// Created by Robin on 09.05.2024.
//

#include "InputNode.h"

CInputNode::CInputNode(std::shared_ptr<CTruthTable> truthTable, size_t row) : table(std::move(truthTable)), row(row) {
    setTitle("Input");
    setStyle(ImFlow::NodeStyle::red());

    for (size_t i = 0; i < table->inputVars.size(); i++) {
        addOUT<bool>(table->inputVars[i], ImFlow::PinStyle::blue())->behaviour(
                [this,i] {
                    return table->getValue(i, this->row);
                });
    }

}
