// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressaa2e00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xaa2e00 LeafAddressaa2e00::Address
#include "LeafAddressaa2e00.h"
extern unsigned char leaf_global;
void* LeafAddressaa2e00::Address() { return &leaf_global; }
