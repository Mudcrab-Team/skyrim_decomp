// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiString: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in fields: GUESS(low); allocation layout observed on the target.
#pragma once
#include <cstddef>
void* AllocateCharStringStorage156b5e0(std::size_t size);
class CharStringCtorLeaf156b5e0
{
public:
    explicit CharStringCtorLeaf156b5e0(char value);
    char* data;
};
