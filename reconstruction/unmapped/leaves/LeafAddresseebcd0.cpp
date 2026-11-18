// Source exposure: binary-analysis; no external implementation reused.
// LeafAddresseebcd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xeebcd0 NiObjectNET::GetRTTI
#include "LeafAddresseebcd0.h"
extern unsigned char leaf_global;
void* LeafAddresseebcd0::Address() { return &leaf_global; }
