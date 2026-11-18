// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// FindNonExcludedDeliveryFunctor::MatchCondition: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/MagicItem.cpp:167
// FindNonExcludedDeliveryFunctor, FindNonExcludedDeliveryFunctor::MatchCondition: GUESS(low)
// FindNonExcludedDeliveryFunctor fields: STANDIN GUESS(low)
// 0x153220 FindNonExcludedDeliveryFunctor::MatchCondition
#include "FindNonExcludedDeliveryFunctor.h"
bool FindNonExcludedDeliveryFunctor::MatchCondition(EffectItem* item) { if (item) { EffectSetting* setting = item->setting; int delivery = setting ? setting->delivery : 5; if (delivery != excluded) return true; } return false; }
