// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress11b3c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x11b3c0 LeafAddress11b3c0::Address
#include "LeafAddress11b3c0.h"
extern unsigned char leaf_global;
void* LeafAddress11b3c0::Address() { return &leaf_global; }
