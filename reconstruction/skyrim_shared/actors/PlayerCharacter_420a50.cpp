/*
 * Labels: v2
 * Build: sse-steam-1-7-104. RVA 0x420a50, 29 bytes; RVA 0x420a80, 29 bytes; RVA 0x420ab0, 29 bytes.
 * Origin: original reconstruction.
 * Evidence: findings/ghidra-import.md
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-sol
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Only the three scaling wrappers are compared; all signatures and ownership remain guessed.
 * The factor is read after calculation; globals have ordinary non-volatile declarations because volatility is not established.
 */
// PlayerCharacter, Function420a50, Function420a80, Function420ab0, CalculateOne, CalculateTwo, ScaleOne, ScaleTwo, ScaleThree: STANDIN GUESS(low)
#include "PlayerCharacter_420a50.h"
float PlayerCharacter::Function420a50() {
    const float value = CalculateOne();
    const float factor = ScaleOne;
    return factor * value;
}
float PlayerCharacter::Function420a80() {
    const float value = CalculateTwo();
    const float factor = ScaleTwo;
    return factor * value;
}
float PlayerCharacter::Function420ab0() {
    const float value = CalculateOne();
    const float factor = ScaleThree;
    return factor * value;
}
