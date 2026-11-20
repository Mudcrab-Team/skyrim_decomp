// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12ced80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12ced80 LeafAddress12ced80::Address
#include "LeafAddress12ced80.h"
extern unsigned char leaf_global;
void* LeafAddress12ced80::Address() { return &leaf_global; }
