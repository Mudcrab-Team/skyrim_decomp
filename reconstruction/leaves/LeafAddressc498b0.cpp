// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc498b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc498b0 LeafAddressc498b0::Address
#include "LeafAddressc498b0.h"
extern unsigned char leaf_global;
void* LeafAddressc498b0::Address() { return &leaf_global; }
