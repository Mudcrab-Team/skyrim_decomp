// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf05960, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf05960 LeafAddressf05960::Address
#include "LeafAddressf05960.h"
extern unsigned char leaf_global;
void* LeafAddressf05960::Address() { return &leaf_global; }
