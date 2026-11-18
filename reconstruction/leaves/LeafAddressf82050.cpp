// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf82050, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf82050 LeafAddressf82050::Address
#include "LeafAddressf82050.h"
extern unsigned char leaf_global;
void* LeafAddressf82050::Address() { return &leaf_global; }
