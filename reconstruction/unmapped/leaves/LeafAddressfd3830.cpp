// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfd3830, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfd3830 LeafAddressfd3830::Address
#include "LeafAddressfd3830.h"
extern unsigned char leaf_global;
void* LeafAddressfd3830::Address() { return &leaf_global; }
