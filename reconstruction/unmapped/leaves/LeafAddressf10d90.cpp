// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf10d90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf10d90 LeafAddressf10d90::Address
#include "LeafAddressf10d90.h"
extern unsigned char leaf_global;
void* LeafAddressf10d90::Address() { return &leaf_global; }
