// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x2955d0 BGSLightingTemplate::InitializeData
#include "BGSLightingTemplate.h"

#include <cstring>

BGSLightingTemplate::BGSLightingTemplate()
{
}

void BGSLightingTemplate::InitializeData()
{
    std::memset(&data, 0, sizeof(data));
    data.fogClamp = 1.0f;
}
