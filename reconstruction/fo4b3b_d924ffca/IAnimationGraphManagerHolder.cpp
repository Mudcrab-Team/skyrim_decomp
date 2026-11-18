// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetGraphVariableCacheSize: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/Animation/IAnimationGraphManagerHolder.cpp:225; signature hint only; target reads a global.
// Semantic names and types: GUESS(low); except where separately attributed.
// 0x6b61b0 IAnimationGraphManagerHolder::GetGraphVariableCacheSize
#include "IAnimationGraphManagerHolder.h"
unsigned int IAnimationGraphManagerHolder::GetGraphVariableCacheSize() const { return graphVariableCacheSize; }
