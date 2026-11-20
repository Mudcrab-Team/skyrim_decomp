// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52e90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52e90 LeafAddressb52e90::Address
#include "LeafAddressb52e90.h"
extern unsigned char leaf_global;
void* LeafAddressb52e90::Address() { return &leaf_global; }
