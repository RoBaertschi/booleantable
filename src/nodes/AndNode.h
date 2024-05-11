//
// Created by Robin on 11.05.2024.
//

#ifndef BOOLEANTABLE_ANDNODE_H
#define BOOLEANTABLE_ANDNODE_H

#include <ImNodeFlow.h>

class CAndNode : public ImFlow::BaseNode {
public:
    std::shared_ptr<ImFlow::InPin<bool>> first;
    std::shared_ptr<ImFlow::InPin<bool>> second;
    CAndNode();

};


#endif //BOOLEANTABLE_ANDNODE_H
