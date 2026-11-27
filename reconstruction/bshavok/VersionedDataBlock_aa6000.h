// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// VersionedDataBlock: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// VersionedDataBlock::ReadBytes: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
#pragma once

struct VersionedDataBlock
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int Read(void* destination, int size);
    int ReadBytes(int size);
};
