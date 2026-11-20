// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xf12b50 NiIntegersExtraData::GetRTTI
#include "NiIntegersExtraData.h"

// NiRTTI: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; only the name pointer
class NiRTTI
{
public:
    const char* name;  // 00
};

// NiRTTI_NiIntegersExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
const NiRTTI NiRTTI_NiIntegersExtraData{};

// RVA 0xf12b50, 8 bytes, NiIntegersExtraData::GetRTTI.
const NiRTTI* NiIntegersExtraData::GetRTTI() const
{
    return &NiRTTI_NiIntegersExtraData;
}
