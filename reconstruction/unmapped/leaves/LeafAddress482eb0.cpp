// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress482eb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x482eb0 LeafAddress482eb0::Address
#include "LeafAddress482eb0.h"
extern unsigned char leaf_global;
void* LeafAddress482eb0::Address() { return &leaf_global; }
