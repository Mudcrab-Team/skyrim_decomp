// TESObjectREFR: GUESS(low) STANDIN
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// 0x2ff6d0 TESObjectREFR::Function2ff6d0
#include "TESObjectREFR.h"
std::uint8_t TESObjectREFR::Function2ff6d0(bool a_flag)
{
 std::uint8_t result = 0;
 if (FindIndex(0, a_flag) != -1) result = 1;
 return result;
}
