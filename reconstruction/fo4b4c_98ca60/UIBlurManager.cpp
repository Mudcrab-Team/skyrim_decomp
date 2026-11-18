// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// UIBlurManager::IncrementBlurCount: SIBLING(fo4-private@1b765c70, author-permission); adapted to target counter width.
// Sibling source: fo4-private@1b765c70 src/Game/Interface/UIBlurManager.cpp:77
// names: GUESS(low); helper names and signature are unverified.
// 0x98ca60 UIBlurManager::IncrementBlurCount
#include "UIBlurManager.h"
void UIBlurManager::IncrementBlurCount() { if (!blurCount) ImageSpaceModifierInstanceForm::Trigger(blurEffect, 1.0f, nullptr); ++blurCount; }
