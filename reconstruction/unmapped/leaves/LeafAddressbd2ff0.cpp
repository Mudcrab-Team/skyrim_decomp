// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbd2ff0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbd2ff0 LeafAddressbd2ff0::Address
#include "LeafAddressbd2ff0.h"
extern unsigned char leaf_global;
void* LeafAddressbd2ff0::Address() { return &leaf_global; }
