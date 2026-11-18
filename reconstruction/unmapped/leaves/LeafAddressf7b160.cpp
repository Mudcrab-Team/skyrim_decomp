// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7b160, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7b160 LeafAddressf7b160::Address
#include "LeafAddressf7b160.h"
extern unsigned char leaf_global;
void* LeafAddressf7b160::Address() { return &leaf_global; }
