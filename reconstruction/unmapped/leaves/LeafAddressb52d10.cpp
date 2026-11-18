// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52d10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52d10 LeafAddressb52d10::Address
#include "LeafAddressb52d10.h"
extern unsigned char leaf_global;
void* LeafAddressb52d10::Address() { return &leaf_global; }
