// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbc5160, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbc5160 LeafAddressbc5160::Address
#include "LeafAddressbc5160.h"
extern unsigned char leaf_global;
void* LeafAddressbc5160::Address() { return &leaf_global; }
