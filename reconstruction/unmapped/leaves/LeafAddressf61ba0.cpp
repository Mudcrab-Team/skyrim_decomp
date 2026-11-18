// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf61ba0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf61ba0 LeafAddressf61ba0::Address
#include "LeafAddressf61ba0.h"
extern unsigned char leaf_global;
void* LeafAddressf61ba0::Address() { return &leaf_global; }
