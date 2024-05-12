//
// Created by Robin on 11.05.2024.
//

#ifndef BOOLEANTABLE_ANDNODE_H
#define BOOLEANTABLE_ANDNODE_H

#include <ImNodeFlow.h>

class CAndNode : public ImFlow::BaseNode {
public:
    int first = 0;
    int second = 1;
    CAndNode();

};


#endif //BOOLEANTABLE_ANDNODE_H
