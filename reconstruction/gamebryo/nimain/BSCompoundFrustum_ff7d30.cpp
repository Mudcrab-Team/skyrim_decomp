// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation from the observed operator append.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xff7d30 BSCompoundFrustum::BeginOperatorGroup
// 0xff7d90 BSCompoundFrustum::EndOperatorGroup
#include "BSCompoundFrustum_ff7d30.h"

inline void BSCompoundFrustum::AppendGroupDelimiter(FrustumOpcode opcode)
{
    if (freeOp + 1 >= functionOperators.capacity) {
        functionOperators.Grow(functionOperators.capacity + 10);
    }
    const auto index = static_cast<unsigned>(freeOp);
    prethreaded = false;
    functionOperators.data[index].opcode = opcode;
    ++freeOp;
}

void BSCompoundFrustum::BeginOperatorGroup()
{
    AppendGroupDelimiter(FrustumOpcode::groupBegin);
}

void BSCompoundFrustum::EndOperatorGroup()
{
    AppendGroupDelimiter(FrustumOpcode::groupEnd);
}
