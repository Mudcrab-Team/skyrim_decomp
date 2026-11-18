// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c800, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c800 LeafAddressb9c800::Address
#include "LeafAddressb9c800.h"
extern unsigned char leaf_global;
void* LeafAddressb9c800::Address() { return &leaf_global; }
