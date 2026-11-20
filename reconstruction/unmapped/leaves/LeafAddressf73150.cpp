// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf73150, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf73150 LeafAddressf73150::Address
#include "LeafAddressf73150.h"
extern unsigned char leaf_global;
void* LeafAddressf73150::Address() { return &leaf_global; }
