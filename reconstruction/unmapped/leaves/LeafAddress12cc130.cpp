// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12cc130, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12cc130 LeafAddress12cc130::Address
#include "LeafAddress12cc130.h"
extern unsigned char leaf_global;
void* LeafAddress12cc130::Address() { return &leaf_global; }
