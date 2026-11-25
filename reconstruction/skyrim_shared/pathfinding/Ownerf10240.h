// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling. Stamped as a twin of matched 0x4f8c60 (skyrim_shared/pathfinding/PathingRequestOptimalLocation_4f8c60): source copied, names replaced by placeholders.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/pathingrequestoptimallocation.cpp:32
// ::CopyTo: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Ownerf10240: GUESS(low) STANDIN
// fPointHeight, m_fUnknownValue2, m_fUnknownValue3, m_fUnknownValue4, BSPathingRequest: GUESS(low) STANDIN
#pragma once
#include "PathingRequestOptimalLocation_4f8c60.h"

class Ownerf10240 : public BSPathingRequest
{
public:
    void CopyTo(BSPathingRequest& destination) override;

    unsigned char padTwin100[40];
    float fPointHeight;
    float m_fUnknownValue2;
    float m_fUnknownValue3;
    float m_fUnknownValue4;
};
static_assert(sizeof(Ownerf10240) == 0x138, "Ownerf10240 size");
