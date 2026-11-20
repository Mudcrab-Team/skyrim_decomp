// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff46a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff46a0 LeafAddressff46a0::Address
#include "LeafAddressff46a0.h"
extern unsigned char leaf_global;
void* LeafAddressff46a0::Address() { return &leaf_global; }
