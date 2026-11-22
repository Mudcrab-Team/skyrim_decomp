// Source exposure: mixed (pinned listing, labelled community declarations and sibling source).
// Code origin: original reconstruction and the cited sibling adaptation.
// Adapted bodies: GetLODLandRootForLevel from fo4-private@1b765c70 (author-permission).
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainManager.cpp:6
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// BGSTerrainManager::GetDiffuseTextureForPoint, BGSTerrainManager::GetNormalTextureForPoint: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSTerrainManager::GetLODLandRootForLevel: SIBLING(fo4-private@1b765c70, author-permission)
// BGSTerrainChunk, GetTexture, TerrainTextureKind, visibility state and root names: GUESS(low)
// 0x5164c0 BGSTerrainManager::GetLODLandRootForLevel
// 0x5166e0 BGSTerrainManager::Function5166e0
// 0x516c20 BGSTerrainManager::Function516c20
// 0x516660 BGSTerrainManager::GetDiffuseTextureForPoint
// 0x5166a0 BGSTerrainManager::GetNormalTextureForPoint
// 0x516b80 BGSTerrainManager::Function516b80
// 0x516bc0 BGSTerrainManager::Function516bc0
#include "BGSTerrainManager.h"
#include "gamebryo/nimain/NiAVObject.h"

NiNode* BGSTerrainManager::GetLODLandRootForLevel(unsigned level) { switch(level) { case 4: return roots[0]; case 8: return roots[1]; case 16: return roots[2]; } NiNode* node = roots[3]; if (level != 32) return nullptr; return node; }

void* BGSTerrainManager::Function5166e0(const void* a_point, bool a_flag)
{
    BGSTerrainNode* node = rootNode;
    if (node) {
        return node->GetChunkForPoint(a_point, a_flag);
    }
    return nullptr;
}

bool BGSTerrainManager::Function516c20()
{
    return g_terrainGlobal->field10 > 0;
}

namespace {
constexpr std::uint32_t kApplicationCulled = 1u;
}

// Look up the diffuse texture associated with the terrain at a point.
NiTexture* BGSTerrainManager::GetDiffuseTextureForPoint(const NiPoint3& a_point)
{
    if (rootNode) {
        auto* chunk = static_cast<BGSTerrainChunk*>(rootNode->GetChunkForPoint(&a_point, false));
        if (chunk) {
            return chunk->GetTexture(TerrainTextureKind::Diffuse);
        }
    }
    return nullptr;
}

// Look up the normal texture associated with the terrain at a point.
NiTexture* BGSTerrainManager::GetNormalTextureForPoint(const NiPoint3& a_point)
{
    if (rootNode) {
        auto* chunk = static_cast<BGSTerrainChunk*>(rootNode->GetChunkForPoint(&a_point, false));
        if (chunk) {
            return chunk->GetTexture(TerrainTextureKind::Normal);
        }
    }
    return nullptr;
}

// Show the terrain roots and update the corresponding visibility.
void BGSTerrainManager::Function516b80()
{
    g_terrainRootA->flags &= ~kApplicationCulled;
    g_terrainRootB->flags &= ~kApplicationCulled;
    g_terrainRootC->flags &= ~kApplicationCulled;
    SetTerrainVisibility(true);
}

// Hide the terrain roots and update the corresponding visibility.
void BGSTerrainManager::Function516bc0()
{
    g_terrainRootA->flags |= kApplicationCulled;
    g_terrainRootB->flags |= kApplicationCulled;
    g_terrainRootC->flags |= kApplicationCulled;
    SetTerrainVisibility(false);
}
