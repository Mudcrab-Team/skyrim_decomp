// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress213c50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x213c50 BSPortal::GetRTTI
#include "LeafAddress213c50.h"
extern unsigned char leaf_global;
void* LeafAddress213c50::Address() { return &leaf_global; }
