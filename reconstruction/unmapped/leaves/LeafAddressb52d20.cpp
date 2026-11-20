// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52d20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52d20 LeafAddressb52d20::Address
#include "LeafAddressb52d20.h"
extern unsigned char leaf_global;
void* LeafAddressb52d20::Address() { return &leaf_global; }
