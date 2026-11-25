// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_0084d0b0::Partition::IsEqual.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00840000_o2.cpp:883
// 0xf07f70 f3m_0084d0b0::Partition::IsEqual
// CI hash: 0xf07f70 ?IsEqual@Partition@f3m_0084d0b0@@QEAA_NPEBU12@@Z
#include "Partition_f07f70.h"

namespace f3m_0084d0b0 {
bool Partition::IsEqual(const Partition* other)
{
    if (vertices1C!=other->vertices1C) return false;
    if (triangles1E!=other->triangles1E) return false;
    if (bones20!=other->bones20) return false;
    if (strips22!=other->strips22) return false;
    if (weightsPerVertex24!=other->weightsPerVertex24) return false;
    if (CompareBones(other)) return false;
    if (memcmp(vertexMap0C,other->vertexMap0C,vertices1C*sizeof(unsigned short))) return false;
    unsigned int weightCount=vertices1C*weightsPerVertex24;
    if (memcmp(weights08,other->weights08,weightCount*sizeof(float))) return false;
    if (!strips22) {
        if (memcmp(indices14,other->indices14,triangles1E*3*sizeof(unsigned short))) return false;
    } else {
        if (memcmp(stripLengths18,other->stripLengths18,strips22*sizeof(unsigned short))) return false;
        if (memcmp(indices14,other->indices14,Func0084d090()*sizeof(unsigned short))) return false;
    }
    if ((!boneIndices10)!=(!other->boneIndices10)) return false;
    if (boneIndices10 && memcmp(boneIndices10,other->boneIndices10,weightCount)) return false;
    return true;
}
}
