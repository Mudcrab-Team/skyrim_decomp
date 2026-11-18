// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52f30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52f30 LeafAddressb52f30::Address
#include "LeafAddressb52f30.h"
extern unsigned char leaf_global;
void* LeafAddressb52f30::Address() { return &leaf_global; }
