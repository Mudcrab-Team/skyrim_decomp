// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress213c20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x213c20 BSMultiBoundAABB::GetRTTI
#include "LeafAddress213c20.h"
extern unsigned char leaf_global;
void* LeafAddress213c20::Address() { return &leaf_global; }
