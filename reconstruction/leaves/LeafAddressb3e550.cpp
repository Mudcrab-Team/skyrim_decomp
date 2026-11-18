// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e550, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e550 LeafAddressb3e550::Address
#include "LeafAddressb3e550.h"
extern unsigned char leaf_global;
void* LeafAddressb3e550::Address() { return &leaf_global; }
