// TESObjectLAND: GUESS(low) STANDIN
/*
 * TESObjectLAND: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x2b2a30 21 bytes; RVA 0x2b2a50 30 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * No external body or declaration has yet been adapted. Stand-ins are unverified.
 */
#include "TESObjectLAND_2b2a30.h"
void TESObjectLAND::Update2b2a30() { Call2b3ce0(); landUpdatePending = true; }
void TESObjectLAND::Update2b2a50() { if (landUpdatePending) { Call2b4490(); } landUpdatePending = false; }
