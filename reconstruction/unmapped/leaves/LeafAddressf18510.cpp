// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf18510, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf18510 LeafAddressf18510::Address
#include "LeafAddressf18510.h"
extern unsigned char leaf_global;
void* LeafAddressf18510::Address() { return &leaf_global; }
