// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSShaderAccumulator, ResetAccumulatorState, itemsList: CRASHLOGGER_PDB(59818@2026.10.24)
// GeometryList, Node, head, tail, count: GUESS(low)
// 0x1520990 BSShaderAccumulator::ResetAccumulatorState
#include "BSShaderAccumulator_1520990.h"

void BSShaderAccumulator::ResetAccumulatorState()
{
    GeometryList::Node* node = itemsList.head;
    while (node) {
        GeometryList::Node* old = node;
        node = node->next;
        old->item = nullptr;
        delete old;
    }
    itemsList.count = 0;
    itemsList.head = nullptr;
    itemsList.tail = nullptr;
}
