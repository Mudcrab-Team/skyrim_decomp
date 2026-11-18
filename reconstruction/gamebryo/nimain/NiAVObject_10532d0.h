/*
 * NiAVObject: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x10532d0 28 bytes; RVA 0x1053300 33 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md; findings/fourth-batch-selection.md (class inventory).
 * Labels: v2
 * Only Function10532d0 and Function1053300 are compared; owner and signatures are inferred.
 * No external body or declaration was adapted. The class declaration is an unverified stand-in.
 */
// NiAVObject: STANDIN EXE_RTTI
// Function1053300, ApplyPositiveValue, Function10532d0, ApplyParameters, Parameters, number, enabled, copy: GUESS(low)
#pragma once

// NiAVObject: STANDIN EXE_RTTI
// Function1053300, ApplyPositiveValue, Function10532d0, ApplyParameters, Parameters, number, enabled, copy: GUESS(low)
struct Parameters { int number; bool enabled; };
class NiAVObject {
public:
    void Function10532d0(int number, bool enabled);
    void ApplyParameters(const Parameters& parameters);
    void Function1053300(float value);
    void ApplyPositiveValue(float* value);
};
