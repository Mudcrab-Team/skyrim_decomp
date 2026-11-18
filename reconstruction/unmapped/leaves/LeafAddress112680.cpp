// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress112680, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x112680 LeafAddress112680::Address
#include "LeafAddress112680.h"
extern unsigned char leaf_global;
void* LeafAddress112680::Address() { return &leaf_global; }
