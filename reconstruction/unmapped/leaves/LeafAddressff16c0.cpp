// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff16c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff16c0 LeafAddressff16c0::Address
#include "LeafAddressff16c0.h"
extern unsigned char leaf_global;
void* LeafAddressff16c0::Address() { return &leaf_global; }
