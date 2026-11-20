// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x1ecd70 TESModelTextureSwap::InitializeDataComponent
#include "TESModelTextureSwap.h"

void TESModelTextureSwap::InitializeDataComponent()
{
    alternateTextures = nullptr;
    numAlternateTextures = 0;
    TESModel::InitializeDataComponent();
}

// TESModelTextureSwap::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void TESModelTextureSwap::ClearDataComponent()
{
    ReleaseAlternateTextures();
    TESModel::ClearDataComponent();
}
