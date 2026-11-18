// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// TESQuest: EXE_RTTI
#pragma once
#include <cstdint>
// TESQuest: EXE_RTTI
// Function3daf50, Search, Query, found, id, context: GUESS(low)
struct Query { bool found; std::uint32_t id; void* context; };
class TESQuest {
public:
 bool Function3daf50(std::uint32_t id, void* context);
 void Search(Query** query);
};
