// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling. Stamped as a twin of matched 0x4f8c60 (skyrim_shared/pathfinding/PathingRequestOptimalLocation_4f8c60): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/pathingrequestoptimallocation.cpp:32
// 0xf10240 Ownerf10240::CopyTo
#include "Ownerf10240.h"

// guess: same compiled code as matched 0x4f8c60 apart from relocated fields; its role here is not established.
void Ownerf10240::CopyTo(BSPathingRequest& destination)
{
    BSPathingRequest::CopyTo(destination);
    auto& request = static_cast<Ownerf10240&>(destination);
    request.fPointHeight = fPointHeight;
    request.m_fUnknownValue2 = m_fUnknownValue2;
    request.m_fUnknownValue3 = m_fUnknownValue3;
    request.m_fUnknownValue4 = m_fUnknownValue4;
}
