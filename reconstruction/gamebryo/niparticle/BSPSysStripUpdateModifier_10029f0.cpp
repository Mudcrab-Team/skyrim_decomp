// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// 0x10029f0 BSPSysStripUpdateModifier::SaveBinary
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysStripUpdateModifier: EXE_RTTI
// NiPSysModifier, NiStream, NiBinaryStream, SaveBinary, oStr, _absoluteCurrentPos, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// fUpdateDeltaTime: SYMBOLS(fo4-pdb)
#include "BSPSysStripUpdateModifier_10029f0.h"

void BSPSysStripUpdateModifier::SaveBinary(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    NiBinaryStream* output = stream.oStr;
    std::uint32_t componentSize = sizeof(fUpdateDeltaTime);
    std::uint32_t written = output->_writeFn(output, &fUpdateDeltaTime,
        sizeof(fUpdateDeltaTime), &componentSize, 1);
    output->_absoluteCurrentPos += written;
}
