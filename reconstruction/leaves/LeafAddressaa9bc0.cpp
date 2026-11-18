// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressaa9bc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xaa9bc0 LeafAddressaa9bc0::Address
#include "LeafAddressaa9bc0.h"
extern unsigned char leaf_global;
void* LeafAddressaa9bc0::Address() { return &leaf_global; }
