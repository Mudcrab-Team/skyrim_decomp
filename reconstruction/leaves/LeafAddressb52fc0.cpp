// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52fc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52fc0 LeafAddressb52fc0::Address
#include "LeafAddressb52fc0.h"
extern unsigned char leaf_global;
void* LeafAddressb52fc0::Address() { return &leaf_global; }
