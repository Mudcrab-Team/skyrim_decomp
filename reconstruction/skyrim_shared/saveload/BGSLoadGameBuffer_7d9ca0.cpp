/*
 * BGSLoadGameBuffer: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x7d9ca0 33 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Function ownership and signature remain unverified; the class declaration is a stand-in.
 * LoadDataEndian declaration adapted from CharmedBaryon/CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT); see header notice.
 */
// BGSLoadGameBuffer: STANDIN EXE_RTTI
// LoadDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function7d9ca0, value: GUESS(low)
#include "BGSLoadGameBuffer_7d9ca0.h"

void BGSLoadGameBuffer::Function7d9ca0() { bool value = true; LoadDataEndian(&value, 1, 1); }
