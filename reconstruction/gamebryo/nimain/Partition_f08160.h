// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Partition: CRASHLOGGER_PDB(59818@2026.10.24)
// Partition::GetStripIndexCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
#pragma once

class NiSkinPartition
{
  public:
    class Partition
    {
      public:
        void* vtable;
        unsigned short* m_pusBonePalette;
        float* m_pfVertexWeights;
        unsigned short* m_pusSourceVertexIndices;
        unsigned char* m_pucBoneIndices;
        unsigned short* m_pusTriList;
        unsigned short* m_pusStripLengths;
        unsigned short m_usVertices, m_usTriangles, m_usBoneCount, m_usStrips, m_usWeightsPerVertex;
        void* m_pkGeometryRendererData;
        unsigned int GetStripIndexCount();
    };
};
