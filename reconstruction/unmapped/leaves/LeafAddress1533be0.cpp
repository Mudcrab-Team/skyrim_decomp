// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1533be0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1533be0 LeafAddress1533be0::Address
#include "LeafAddress1533be0.h"
extern unsigned char leaf_global;
void* LeafAddress1533be0::Address() { return &leaf_global; }
