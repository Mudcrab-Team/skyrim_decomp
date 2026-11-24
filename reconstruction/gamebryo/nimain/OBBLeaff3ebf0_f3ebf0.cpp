// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf3ebf0 OBBLeaff3ebf0::~OBBLeaff3ebf0
#include "OBBLeaff3ebf0_f3ebf0.h"

OBBLeaff3ebf0::~OBBLeaff3ebf0()
{
    // NOTE: the original only releases the right child when the left child exists.
    if (left) {
        delete left;
        delete right;
    }
}
