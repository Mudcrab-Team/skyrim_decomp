// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh.json
// Adapted bodies: none
// 0x151e890 BSShaderAccumulator::FinishAccumulatingCollectGeometry
#include "BSShaderAccumulator_151e890.h"

bool BSShaderAccumulator::FinishAccumulatingCollectGeometry(BSGeometry* geometry)
{
    GeometryListNode* node = new GeometryListNode;
    node->geometry = geometry;
    node->next = nullptr;
    node->previous = tail;
    if (tail)
        tail->next = node;
    else
        head = node;
    ++count;
    tail = node;
    return true;
}
