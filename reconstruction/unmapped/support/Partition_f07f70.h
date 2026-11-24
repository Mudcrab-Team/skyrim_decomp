// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Partition: CRASHLOGGER_PDB(59818@2026.10.24)
// Partition::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <string.h>

namespace f3m_0084d0b0 {


struct Partition {
    unsigned int unk00;
    unsigned short* bones04;
    float* weights08;
    unsigned short* vertexMap0C;
    unsigned char* boneIndices10;
    unsigned short* indices14;
    unsigned short* stripLengths18;
    unsigned short vertices1C;
    unsigned short triangles1E;
    unsigned short bones20;
    unsigned short strips22;
    unsigned short weightsPerVertex24;
    inline int CompareBones(const Partition* b) const { return memcmp(bones04,b->bones04,bones20*sizeof(unsigned short)); }
    unsigned int Func0084d090();
    bool IsEqual(const Partition*);
};

}
