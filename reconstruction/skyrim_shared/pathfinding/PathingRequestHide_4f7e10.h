// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// Adapted bodies: PathingRequestHide::~PathingRequestHide follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/pathingrequesthide.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/pathingrequesthide.cpp:14
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/pathingrequesthide.cpp:47
// PathingRequestHide, PathingRequestHide::~PathingRequestHide: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// BSPathingRequest, BSPathingRequest::~BSPathingRequest, BSPathingLocation, BSPathingLocation::~BSPathingLocation: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ThreatLocation, fMinHideDistance: SYMBOLS(fo4-pdb)
// unknown08, unknown00: GUESS(low); unaccessed storage.
#pragma once

#include <cstdint>

void operator delete(void*, unsigned __int64) noexcept;

// The deleting entry destroys the location and base without installing a derived vtable.
class __declspec(novtable) BSPathingRequest
{
public:
    virtual ~BSPathingRequest();

    std::uint64_t unknown08[31];
};

struct BSPathingLocation
{
    ~BSPathingLocation();
    std::uint64_t unknown00[6];
};

class PathingRequestHide : public BSPathingRequest
{
public:
    PathingRequestHide();
    ~PathingRequestHide() override = default;

    BSPathingLocation ThreatLocation;
    float fMinHideDistance;
};
static_assert(sizeof(PathingRequestHide) == 0x138, "PathingRequestHide size");
