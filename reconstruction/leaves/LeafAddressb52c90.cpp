// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52c90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52c90 LeafAddressb52c90::Address
#include "LeafAddressb52c90.h"
extern unsigned char leaf_global;
void* LeafAddressb52c90::Address() { return &leaf_global; }
