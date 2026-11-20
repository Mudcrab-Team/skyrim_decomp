// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress482ea0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x482ea0 LeafAddress482ea0::Address
#include "LeafAddress482ea0.h"
extern unsigned char leaf_global;
void* LeafAddress482ea0::Address() { return &leaf_global; }
