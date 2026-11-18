// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1521e20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1521e20 BSShaderAccumulator::GetRTTI
#include "LeafAddress1521e20.h"
extern unsigned char leaf_global;
void* LeafAddress1521e20::Address() { return &leaf_global; }
