// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress6b5af0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x6b5af0 LeafAddress6b5af0::Address
#include "LeafAddress6b5af0.h"
extern unsigned char leaf_global;
void* LeafAddress6b5af0::Address() { return &leaf_global; }
