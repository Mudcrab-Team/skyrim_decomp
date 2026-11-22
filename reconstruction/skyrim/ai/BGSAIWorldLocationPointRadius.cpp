// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of point-radius accessors.
// Adapted bodies: none.
// 0x448e30 BGSAIWorldLocationPointRadius::Slot8
// 0x448e10 BGSAIWorldLocationPointRadius::Function448e10
// 0x448e60 BGSAIWorldLocationPointRadius::Function448e60
// 0x448e90 BGSAIWorldLocationPointRadius::Function448e90
// 0x448ed0 BGSAIWorldLocationPointRadius::Function448ed0
// 0x449810 BGSAIWorldLocationPointRadius::Function449810
#include "BGSAIWorldLocationPointRadius.h"

void* BGSAIWorldLocationPointRadius::Slot8() const
{
    return member;
}

float BGSAIWorldLocationPointRadius::Function448e10() const
{
    return field2C;
}

std::uint8_t BGSAIWorldLocationPointRadius::Function448e60() const
{
    return field30;
}

bool BGSAIWorldLocationPointRadius::Function448e90(PointLocationResult* a_out) const
{
    void* space = member ? member : fallbackSpace;
    float px = pos.x;
    float py = pos.y;
    float pz = pos.z;
    a_out->pos.x = px;
    a_out->pos.y = py;
    a_out->pos.z = pz;
    a_out->space = space;
    return space != nullptr;
}

std::uint8_t BGSAIWorldLocationPointRadius::Function448ed0() const
{
    return field31;
}

float BGSAIWorldLocationPointRadius::Function449810() const
{
    return field28;
}
