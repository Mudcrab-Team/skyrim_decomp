// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf76610, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf76610 LeafAddressf76610::Address
#include "LeafAddressf76610.h"
extern unsigned char leaf_global;
void* LeafAddressf76610::Address() { return &leaf_global; }
