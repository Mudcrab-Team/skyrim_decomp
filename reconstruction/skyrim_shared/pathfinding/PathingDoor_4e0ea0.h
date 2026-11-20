// PathingDoor: GUESS(low) STANDIN
/*
 * PathingDoor: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x4e0ea0 33 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * No external body or declaration has yet been adapted. Stand-ins are unverified.
 */
#pragma once
#include <cstdint>
// PathingDoor, PathingDoor::Function4e0ea0, LookupDoorValue, doorKey: GUESS(low) STANDIN
extern const char doorKey[];
void LookupDoorValue(std::uint32_t*, const char*, std::uint32_t);
class PathingDoor { public: std::uint32_t Function4e0ea0(); };
