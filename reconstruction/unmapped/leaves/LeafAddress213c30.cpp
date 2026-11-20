// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress213c30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x213c30 BSMultiBoundOBB::GetRTTI
#include "LeafAddress213c30.h"
extern unsigned char leaf_global;
void* LeafAddress213c30::Address() { return &leaf_global; }
