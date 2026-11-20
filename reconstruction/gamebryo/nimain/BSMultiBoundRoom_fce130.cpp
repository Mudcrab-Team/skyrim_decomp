// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of joined room-bound traversal.
// 0xfce130 BSMultiBoundRoom::CheckBound2
// 0xfce1c0 BSMultiBoundRoom::CheckBound1
#include "BSMultiBoundRoom_fce130.h"

template <typename Bound>
BSMBCullResult BSMultiBoundRoom::CheckJoinedBounds(
    const Bound& target, BSMBCullResult (*RoomBoundShapeVTable::*check)(BSMultiBoundShape*, const Bound&)) const
{
    auto* shape = multiBound->shape;
    auto result = (shape->vtable->*check)(shape, target);
    if (result != BSMBCullResult::kCullVisible && joinedMultiBoundList.count != 0) {
        auto* node = joinedMultiBoundList.head;
        do {
            if (!node) {
                break;
            }
            auto& bound = node->bound;
            node = node->next;
            auto* joined = bound->shape;
            const auto next = (joined->vtable->*check)(joined, target);
            if (next != BSMBCullResult::kCullUntested) {
                result = next;
            }
        } while (result != BSMBCullResult::kCullVisible);
    }
    return result;
}

BSMBCullResult BSMultiBoundRoom::CheckBound1(const BSMultiBound& target) const
{
    return CheckJoinedBounds(target, &RoomBoundShapeVTable::CheckBound1);
}

BSMBCullResult BSMultiBoundRoom::CheckBound2(const NiBound& target) const
{
    return CheckJoinedBounds(target, &RoomBoundShapeVTable::CheckBound2);
}
