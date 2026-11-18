// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52ed0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52ed0 LeafAddressb52ed0::Address
#include "LeafAddressb52ed0.h"
extern unsigned char leaf_global;
void* LeafAddressb52ed0::Address() { return &leaf_global; }
