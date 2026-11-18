// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// MatchCondition: Sibling source: fo4-private@1b765c70 src/Shared/Magic/MagicItem.cpp:161
// FindEqualsFunctor, FindEqualsFunctor::MatchCondition: SIBLING(fo4-private@1b765c70, author-permission)
// 0x153210 FindEqualsFunctor::MatchCondition
#include "FindEqualsFunctor.h"

bool FindEqualsFunctor::MatchCondition(EffectItem* item) { return item == lookFor; }
