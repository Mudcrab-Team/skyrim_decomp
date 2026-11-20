// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbafc30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbafc30 LeafAddressbafc30::Address
#include "LeafAddressbafc30.h"
extern unsigned char leaf_global;
void* LeafAddressbafc30::Address() { return &leaf_global; }
