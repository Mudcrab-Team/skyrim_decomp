// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress494a80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x494a80 LeafAddress494a80::Address
#include "LeafAddress494a80.h"
extern unsigned char leaf_global;
void* LeafAddress494a80::Address() { return &leaf_global; }
