// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc498c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc498c0 LeafAddressc498c0::Address
#include "LeafAddressc498c0.h"
extern unsigned char leaf_global;
void* LeafAddressc498c0::Address() { return &leaf_global; }
