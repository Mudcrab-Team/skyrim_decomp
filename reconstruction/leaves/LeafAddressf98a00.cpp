// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf98a00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf98a00 LeafAddressf98a00::Address
#include "LeafAddressf98a00.h"
extern unsigned char leaf_global;
void* LeafAddressf98a00::Address() { return &leaf_global; }
