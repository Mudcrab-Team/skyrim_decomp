// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x1c6ff0 ArrayDtorLeaf1c6ff0::~ArrayDtorLeaf1c6ff0
#include "ArrayDtorLeaf1c6ff0_1c6ff0.h"

ArrayDtorBase::~ArrayDtorBase()
{
    ReleaseArrayMemory(data);
}
ArrayDtorLeaf1c6ff0::ArrayDtorLeaf1c6ff0() = default;
ArrayDtorLeaf1c6ff0::~ArrayDtorLeaf1c6ff0() = default;
