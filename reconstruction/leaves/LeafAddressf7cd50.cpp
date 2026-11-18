// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7cd50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7cd50 LeafAddressf7cd50::Address
#include "LeafAddressf7cd50.h"
extern unsigned char leaf_global;
void* LeafAddressf7cd50::Address() { return &leaf_global; }
