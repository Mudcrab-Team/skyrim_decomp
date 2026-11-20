// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa1400, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa1400 LeafAddressfa1400::Address
#include "LeafAddressfa1400.h"
extern unsigned char leaf_global;
void* LeafAddressfa1400::Address() { return &leaf_global; }
