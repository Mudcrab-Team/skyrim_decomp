// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// Adapted bodies: PathingRequestOptimalLocation::CopyTo follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/pathingrequestoptimallocation.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/pathingrequestoptimallocation.cpp:32
// PathingRequestOptimalLocation, PathingRequestOptimalLocation::CopyTo: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// fPointHeight, m_fUnknownValue2, m_fUnknownValue3, m_fUnknownValue4: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// BSPathingRequest, BSPathingRequest::~BSPathingRequest, ::GetType, ::CopyTo: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown08: GUESS(low); unaccessed base request storage.
#pragma once

#include <cstdint>

class BSPathingRequest
{
public:
    virtual ~BSPathingRequest();
    virtual std::uint32_t GetType();
    virtual void CopyTo(BSPathingRequest& destination);

    std::uint64_t unknown08[31];
};

class PathingRequestOptimalLocation : public BSPathingRequest
{
public:
    void CopyTo(BSPathingRequest& destination) override;

    float fPointHeight;
    float m_fUnknownValue2;
    float m_fUnknownValue3;
    float m_fUnknownValue4;
};
static_assert(sizeof(PathingRequestOptimalLocation) == 0x110, "PathingRequestOptimalLocation size");
