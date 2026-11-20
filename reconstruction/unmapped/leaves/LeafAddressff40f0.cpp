// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff40f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff40f0 LeafAddressff40f0::Address
#include "LeafAddressff40f0.h"
extern unsigned char leaf_global;
void* LeafAddressff40f0::Address() { return &leaf_global; }
