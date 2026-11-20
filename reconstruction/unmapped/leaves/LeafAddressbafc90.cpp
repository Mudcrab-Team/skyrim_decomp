// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbafc90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbafc90 LeafAddressbafc90::Address
#include "LeafAddressbafc90.h"
extern unsigned char leaf_global;
void* LeafAddressbafc90::Address() { return &leaf_global; }
