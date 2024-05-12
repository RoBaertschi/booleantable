//
// Created by Robin on 11.05.2024.
//

#include "AndNode.h"

CAndNode::CAndNode() {
    setTitle("And");
    addIN_uid<bool>(first, "First", false, ImFlow::ConnectionFilter::SameType());
    addIN_uid<bool>(second, "Second", false, ImFlow::ConnectionFilter::SameType());

    addOUT<bool>("Out", ImFlow::PinStyle::red())->behaviour([this] {
        return getInVal<bool>(first) && getInVal<bool>(second);
    });
}
