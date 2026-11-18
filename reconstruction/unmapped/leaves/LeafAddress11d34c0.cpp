// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress11d34c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x11d34c0 LeafAddress11d34c0::Address
#include "LeafAddress11d34c0.h"
extern unsigned char leaf_global;
void* LeafAddress11d34c0::Address() { return &leaf_global; }
