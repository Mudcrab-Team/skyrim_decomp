// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52e00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52e00 LeafAddressb52e00::Address
#include "LeafAddressb52e00.h"
extern unsigned char leaf_global;
void* LeafAddressb52e00::Address() { return &leaf_global; }
