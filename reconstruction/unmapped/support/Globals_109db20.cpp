// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: bhkRagdollTemplate::SaveBinary_140DF5050.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00ca0000_o2.cpp:7194
// 0x109db20 bhkRagdollTemplate::SaveBinary_140DF5050
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00ca0000_o2.cpp:6603
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00ca0000_o2.cpp:6978
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00ca0000_o2.cpp:6611
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00ca0000_o2.cpp:6986
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00ca0000_o2.cpp:6788
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00ca0000_o2.cpp:7163
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00ca0000_o2.cpp:6794
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00ca0000_o2.cpp:7169
// Adapted helpers: BinaryWrite, BinaryRead, BCB9F60BinaryStreamSave, BCB9F60SaveBinary
#include "Globals_109db20.h"

void bhkRagdollTemplate::SaveBinary_140DF5050(BCB9F60Stream& kStream)
{
    BCB9F60ExtraData::SaveBinary(kStream);
    unsigned int ItemUpdateArray = m_uiCount;
    BCB9F60SaveBinary(kStream, ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        kStream.SaveLinkID(m_ppkObjects[i]);
}
