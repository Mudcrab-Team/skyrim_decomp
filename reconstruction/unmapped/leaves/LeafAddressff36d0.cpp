// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff36d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff36d0 LeafAddressff36d0::Address
#include "LeafAddressff36d0.h"
extern unsigned char leaf_global;
void* LeafAddressff36d0::Address() { return &leaf_global; }
