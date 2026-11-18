// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// TESQuest: EXE_RTTI
// 0x3daf50 TESQuest::Function3daf50
#include "TESQuest.h"
bool TESQuest::Function3daf50(std::uint32_t id, void* context) {
 Query query{false, id, context};
 Query* current = &query;
 Search(&current);
 return query.found;
}
