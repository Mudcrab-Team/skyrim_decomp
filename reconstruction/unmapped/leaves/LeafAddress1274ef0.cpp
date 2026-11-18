// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1274ef0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1274ef0 LeafAddress1274ef0::Address
#include "LeafAddress1274ef0.h"
extern unsigned char leaf_global;
void* LeafAddress1274ef0::Address() { return &leaf_global; }
