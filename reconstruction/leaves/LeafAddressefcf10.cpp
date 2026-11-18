// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressefcf10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xefcf10 LeafAddressefcf10::Address
#include "LeafAddressefcf10.h"
extern unsigned char leaf_global;
void* LeafAddressefcf10::Address() { return &leaf_global; }
