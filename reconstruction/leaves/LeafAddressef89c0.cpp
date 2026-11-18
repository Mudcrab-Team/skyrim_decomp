// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressef89c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xef89c0 LeafAddressef89c0::Address
#include "LeafAddressef89c0.h"
extern unsigned char leaf_global;
void* LeafAddressef89c0::Address() { return &leaf_global; }
