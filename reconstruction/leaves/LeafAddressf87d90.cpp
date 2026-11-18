// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf87d90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf87d90 LeafAddressf87d90::Address
#include "LeafAddressf87d90.h"
extern unsigned char leaf_global;
void* LeafAddressf87d90::Address() { return &leaf_global; }
