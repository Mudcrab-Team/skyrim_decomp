// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4b57f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4b57f0 BSTempEffectSPG::GetRTTI
#include "LeafAddress4b57f0.h"
extern unsigned char leaf_global;
void* LeafAddress4b57f0::Address() { return &leaf_global; }
