// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1188a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1188a0 LeafAddress1188a0::Address
#include "LeafAddress1188a0.h"
extern unsigned char leaf_global;
void* LeafAddress1188a0::Address() { return &leaf_global; }
