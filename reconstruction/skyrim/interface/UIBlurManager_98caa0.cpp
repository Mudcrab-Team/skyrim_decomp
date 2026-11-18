// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// UIBlurManager::DecrementBlurCount: SIBLING(fo4-private@1b765c70, author-permission); adapted to target counter width.
// Sibling source: fo4-private@1b765c70 src/Game/Interface/UIBlurManager.cpp:87
// names: GUESS(low); helper names and signature are unverified.
// 0x98caa0 UIBlurManager::DecrementBlurCount
#include "UIBlurManager_98caa0.h"
void UIBlurManager::DecrementBlurCount() { if (blurCount && !--blurCount) ImageSpaceModifierInstanceForm::Stop(blurEffect); }
