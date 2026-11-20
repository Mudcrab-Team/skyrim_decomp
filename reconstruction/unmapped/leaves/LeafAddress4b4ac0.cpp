// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4b4ac0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4b4ac0 BSTempEffectSimpleDecal::GetRTTI
#include "LeafAddress4b4ac0.h"
extern unsigned char leaf_global;
void* LeafAddress4b4ac0::Address() { return &leaf_global; }
