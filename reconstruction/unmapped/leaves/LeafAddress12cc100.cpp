// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12cc100, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12cc100 LeafAddress12cc100::Address
#include "LeafAddress12cc100.h"
extern unsigned char leaf_global;
void* LeafAddress12cc100::Address() { return &leaf_global; }
