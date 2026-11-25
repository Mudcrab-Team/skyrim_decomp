// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiString: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in class and field: GUESS(low)
#pragma once
#include <cstddef>

struct NiStringBuffer156b540
{
    explicit NiStringBuffer156b540(std::size_t size);
    char* data;
};
char* AllocateStringBuffer(std::size_t size);
