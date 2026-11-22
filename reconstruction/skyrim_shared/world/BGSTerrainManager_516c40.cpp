// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of the active worldspace terrain flag query.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x516c40 BGSTerrainManager::QueryCurrentTerrainFlag
#include "BGSTerrainManager_516c40.h"
#include "TESWorldSpace_30db20.h"
#include "bsmain/TES_1a9280.h"

// g_tes: GUESS(low)
extern TES* g_tes;

bool BGSTerrainManager::QueryCurrentTerrainFlag()
{
    const auto* world = static_cast<TESWorldSpace*>(g_tes->Function1a2610());
    if (world && world->GetTerrainManager() && world->GetTerrainManager()->unk36 != 0) {
        return true;
    }
    return false;
}
