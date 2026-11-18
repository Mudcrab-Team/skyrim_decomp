// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
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
