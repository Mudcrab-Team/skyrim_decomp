// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiOBBNode::~NiOBBNode.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00ea0000_o2.cpp:394
// 0xf3ebf0 NiOBBNode::~NiOBBNode
#include "NiOBBNode_f3ebf0.h"

NiOBBNode::~NiOBBNode()
{
    if (m_pkPrimary)
    {
        delete m_pkPrimary;
        delete m_pkSecondary;
    }
}
