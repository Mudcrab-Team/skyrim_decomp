// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1aa050 Obj1aa050::CountTriangles
// Adapted bodies: none.
#include "Obj1aa050.h"

// Recursively sums triangle counts across all geometry nodes beneath a_node.
std::uint32_t Obj1aa050::CountTriangles(Node1aa050* a_node, bool a_includeHidden)
{
    std::uint32_t total = 0;
    if (!a_node) {
        return 0;
    }
    for (std::uint32_t i = 0; i < a_node->count122; ++i) {
        Node1aa050* child = a_node->children118[i];
        if (child) {
            Geom1aa050* geom = child->AsGeometry();
            if (geom) {
                if (a_includeHidden || (geom->flagsF4 & 1) == 0) {
                    total += geom->triCount15A;
                }
            } else {
                total += CountTriangles(child->AsNode(), a_includeHidden);
            }
        }
    }
    return total;
}
