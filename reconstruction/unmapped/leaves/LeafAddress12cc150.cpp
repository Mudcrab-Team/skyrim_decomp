// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12cc150, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12cc150 LeafAddress12cc150::Address
#include "LeafAddress12cc150.h"
extern unsigned char leaf_global;
void* LeafAddress12cc150::Address() { return &leaf_global; }
