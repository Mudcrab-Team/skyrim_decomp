// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9ca60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9ca60 LeafAddressb9ca60::Address
#include "LeafAddressb9ca60.h"
extern unsigned char leaf_global;
void* LeafAddressb9ca60::Address() { return &leaf_global; }
