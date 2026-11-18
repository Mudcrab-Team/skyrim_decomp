// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/MagicItem.cpp:50 (MagicItem::GetFixedCastDuration)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/MagicItem.cpp:56 (MagicItem::GetRange)
// MagicItem, GetFixedCastDuration, GetRange: GUESS(low)
#pragma once

class MagicItem
{
public:
    float GetFixedCastDuration() const;
    float GetRange() const;
};
