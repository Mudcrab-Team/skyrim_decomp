// Source exposure: mixed (pinned listing, labelled community declarations and sibling source).
// Code origin: original reconstruction and the cited sibling adaptation. Stamped as a twin of matched 0x5166e0 (skyrim_shared/world/BGSTerrainManager): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainManager.cpp:6
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: Function516740 original, from the listing and community declarations only
// 0xab2380 Ownerab2380::Functionab2380
#include "Ownerab2380.h"
#include "gamebryo/nimain/NiAVObject.h"

// guess: same compiled code as matched 0x5166e0 apart from relocated fields; its role here is not established.
void* Ownerab2380::Functionab2380(const void* a_point, bool a_flag)
{
    BGSTerrainNode* node = rootNode;
    if (node) {
        return node->GetChunkForPoint(a_point, a_flag);
    }
    return nullptr;
}
