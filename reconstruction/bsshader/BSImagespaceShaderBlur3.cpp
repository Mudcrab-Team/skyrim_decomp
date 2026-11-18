// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1507e00 BSImagespaceShaderBlur3::~BSImagespaceShaderBlur3
// 0x1509cb0 BSImagespaceShaderBlur3::Unk_0D
#include "BSImagespaceShaderBlur3.h"

// Not compared on its own: the compiler emits the vftable here, and with it the deleting
// destructor that is compared. The destructor itself stays undefined here so that the compiler
// calls the separate complete destructor, as the listing does.
BSImagespaceShaderBlur3::BSImagespaceShaderBlur3()
{
}

BSImagespaceShaderBlur3Table BSImagespaceShaderBlur3::Unk_0D()
{
    BSImagespaceShaderBlur3Table table;
    table.name00 = "TEXTAP";
    table.data08 = &g_blurDataA;
    table.name10 = "COLORRANGE";
    table.data18 = &g_blurDataB;
    table.ptr20 = nullptr;
    table.ptr28 = nullptr;
    return table;
}
