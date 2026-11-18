/*
 * BSFile: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0xeaded0 32 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Function ownership and signature remain unverified; the class declaration is a stand-in.
 * No external body or declaration has yet been adapted. Stand-ins are unverified.
 */
// BSFile: STANDIN EXE_RTTI
// Functioneaded0: GUESS(low)
// GetFileAttributesA: OBSERVED
#pragma once

class BSFile {
public:
    static bool Functioneaded0(const char* path);
};
