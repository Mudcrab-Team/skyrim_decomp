// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// UIBlurManager::IncrementBlurCount: SIBLING(fo4-private@1b765c70, author-permission); adapted to target counter width.
// Sibling source: fo4-private@1b765c70 src/Game/Interface/UIBlurManager.cpp:77
// names: GUESS(low); helper names and signature are unverified.
// Adapted bodies: IncrementBlurCount from fo4-private@1b765c70; Function98cad0, Function98cae0, Function98cb00 original.
// 0x98ca60 UIBlurManager::IncrementBlurCount
// 0x98cad0 UIBlurManager::Function98cad0
// 0x98cae0 UIBlurManager::Function98cae0
// 0x98cb00 UIBlurManager::Function98cb00
#include "UIBlurManager.h"

void UIBlurManager::IncrementBlurCount() { if (!blurCount) ImageSpaceModifierInstanceForm::Trigger(blurEffect, 1.0f, nullptr); ++blurCount; }

void UIBlurManager::Function98cad0()
{
    ImageSpaceModifierInstanceForm::Stop(blurEffect);
}

void UIBlurManager::Function98cae0()
{
    if (blurCount > 0) {
        ImageSpaceModifierInstanceForm::Trigger(blurEffect, 1.0f, nullptr);
    }
}

void UIBlurManager::Function98cb00()
{
    g_uiBlurManagerInstance = nullptr;
}
