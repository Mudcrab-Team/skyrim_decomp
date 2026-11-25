// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0xf10f30 (gamebryo/nimain/NiFloatExtraData_f10eb0): source copied, names replaced by placeholders.
// 0xf45ad0 Ownerf45ad0::SaveBinary
#include "Ownerf45ad0.h"

// guess: same compiled code as matched 0xf10f30 apart from relocated fields; its role here is not established.
void Ownerf45ad0::SaveBinary(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(value);
    const auto transferred = binary->_writeFn(binary, &value, sizeof(value), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}
