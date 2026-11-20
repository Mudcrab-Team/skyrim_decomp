// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layouts for the primary and joined room bounds.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSMultiBoundRoom, BSMultiBound, BSMultiBoundShape, NiBound, joinedMultiBoundList, multiBound, CheckBound1, CheckBound2: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// RoomBoundShapeVTable, JoinedMultiBound, CheckJoinedBounds: GUESS(low)
#pragma once

#include <cstdint>

struct BSMultiBound;
class NiBound;
class BSMultiBoundShape;

enum class BSMBCullResult : std::uint32_t
{
    kCullUntested = 0,
    kCullVisible = 1,
    kCullCulled = 2,
    kCullOccluded = 3
};

struct RoomBoundShapeVTable
{
    std::uint8_t unknown00[0x138];
    BSMBCullResult (*CheckBound1)(BSMultiBoundShape*, const BSMultiBound&);
    BSMBCullResult (*CheckBound2)(BSMultiBoundShape*, const NiBound&);
};

class BSMultiBoundShape
{
public:
    const RoomBoundShapeVTable* vtable;
};

struct BSMultiBound
{
    std::uint8_t unknown00[0x18];
    BSMultiBoundShape* shape;
};

struct JoinedMultiBound
{
    JoinedMultiBound* next;
    JoinedMultiBound* previous;
    BSMultiBound* bound;
};

class BSMultiBoundRoom
{
public:
    BSMBCullResult CheckBound1(const BSMultiBound& target) const;
    BSMBCullResult CheckBound2(const NiBound& target) const;

private:
    template <typename Bound>
    BSMBCullResult CheckJoinedBounds(
        const Bound& target, BSMBCullResult (*RoomBoundShapeVTable::*check)(BSMultiBoundShape*, const Bound&)) const;

    std::uint8_t unknown00[0x128];
    BSMultiBound* multiBound;
    std::uint8_t unknown130[0x38];
    struct {
        JoinedMultiBound* head;
        JoinedMultiBound* tail;
        std::uint32_t count;
    } joinedMultiBoundList;
};
