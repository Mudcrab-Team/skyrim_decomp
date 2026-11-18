// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf97bb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf97bb0 LeafAddressf97bb0::Address
#include "LeafAddressf97bb0.h"
extern unsigned char leaf_global;
void* LeafAddressf97bb0::Address() { return &leaf_global; }
