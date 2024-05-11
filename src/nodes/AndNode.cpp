//
// Created by Robin on 11.05.2024.
//

#include "AndNode.h"

CAndNode::CAndNode() {
    setTitle("And");
    first = addIN<bool>("First", false, ImFlow::ConnectionFilter::SameType());
    second = addIN<bool>("Second", false, ImFlow::ConnectionFilter::SameType());

    addOUT<bool>("Out", ImFlow::PinStyle::red())->behaviour([this] {
        return first.get() && second.get();
    });
}
