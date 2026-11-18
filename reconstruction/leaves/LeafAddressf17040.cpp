// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf17040, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf17040 LeafAddressf17040::Address
#include "LeafAddressf17040.h"
extern unsigned char leaf_global;
void* LeafAddressf17040::Address() { return &leaf_global; }
