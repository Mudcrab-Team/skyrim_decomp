// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12cc140, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12cc140 LeafAddress12cc140::Address
#include "LeafAddress12cc140.h"
extern unsigned char leaf_global;
void* LeafAddress12cc140::Address() { return &leaf_global; }
