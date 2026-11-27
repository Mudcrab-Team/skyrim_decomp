// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: fnv_00a7fa20::NiBinaryExtraData::SaveBinary_140C83D50.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nibinaryextradata.cpp:290
// 0xf0fa90 fnv_00a7fa20::NiBinaryExtraData::SaveBinary_140C83D50
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nicollision/nicollisiondata.cpp:1345
// Adapted helpers: BinaryRead, Read
#include "NiBinaryExtraData_f0fa90.h"

namespace fnv_00a7fa20 {
void NiBinaryExtraData::SaveBinary_140C83D50(NiStreamLike* apStream)
{
    this->Func00a7b2c0(apStream);
    FadeNode* node = apStream->unk250;
    {
        int flag = 4;
        node->unk04 += node->unk0c(node, &this->unk10, 4, &flag, 1);
    }
    unsigned int count = this->unk10;
    if (count > 0)
    {
        FadeNode* node = apStream->unk250;
        void* data = this->unk0c;
        {
            int flag = 1;
            node->unk04 += node->unk0c(node, data, count, &flag, 1);
        }
    }
}
}
