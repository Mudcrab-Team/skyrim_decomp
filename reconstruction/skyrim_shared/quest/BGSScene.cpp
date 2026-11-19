// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3aa560 BGSScene::~BGSScene
// 0x3a9170 BGSScene::Revert
#include "BGSScene.h"

// RevertScenePhase, g_sceneTimeScale: GUESS(low); callee at 0x3ae110 and float global at 0x31e0310.
void RevertScenePhase(BGSScenePhase* a_phase, BGSLoadFormBuffer* a_buf);
extern float g_sceneTimeScale;

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BGSScene::BGSScene()
{
}

void BGSScene::Revert(BGSLoadFormBuffer* a_buf)
{
    TESForm::Revert(a_buf);
    unkB0 = 0;
    unkB1 = 0;
    unkBC = 0xFFFFFFFF;
    unkB2 = 0;

    for (std::uint32_t i = 0; i < actions._size; ++i) {
        actions._data[i]->Slot0B(a_buf);
    }
    for (std::uint32_t i = 0; i < phases._size; ++i) {
        RevertScenePhase(phases._data[i], a_buf);
    }

    unkB3 = 0;
    unkB4 = 0;
    if (unkB5 != 0) {
        g_sceneTimeScale = 0.0f;
    }
    unkB6 = 0;
    unkB7 = 0;
    unkB8 = 0;
}
