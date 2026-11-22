// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of the unloaded center and indexed cell operations.
// 0x226c40 GridCellArray::ResetCenter
// 0x227120 GridCellArray::GetCellSlot
// 0x2271d0 GridCellArray::IsCellAttached
// 0x2272b0 GridCellArray::SetCenter
// 0x2273a0 GridCellArray::ClearItem
#include "GridCellArray_226c40.h"

// NotifyGridCenter: GUESS(low)
void NotifyGridCenter(const GridCenter& position);

void GridCellArray::ResetCenter()
{
    unk0C = static_cast<std::uint32_t>(-10000);
    unk08 = static_cast<std::uint32_t>(-10000);
}

TESObjectCELL** GridCellArray::GetCellSlot(std::uint32_t x, std::uint32_t y) const
{
    return x < length && y < length ? cells + (x * length + y) : nullptr;
}

bool GridCellArray::IsCellAttached(std::uint32_t x, std::uint32_t y) const
{
    const auto* cell = *GetCellSlot(x, y);
    if (cell) {
        return cell->cellState == TESObjectCELL::CellState::kAttached;
    }
    return false;
}

bool GridCellArray::SetCenter(std::int32_t x, std::int32_t y)
{
    if (GridArray::SetCenter(x, y)) {
        position.z = 0.0f;
        position.x = static_cast<float>(x * 4096);
        position.y = static_cast<float>(y * 4096);
        NotifyGridCenter(position);
        land3DAttached = false;
        return true;
    }
    return false;
}

void GridCellArray::ClearItem(std::uint32_t x, std::uint32_t y)
{
    *GetCellSlot(x, y) = nullptr;
    land3DAttached = false;
}
