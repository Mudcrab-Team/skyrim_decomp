// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf8d480, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf8d480 LeafAddressf8d480::Address
#include "LeafAddressf8d480.h"
extern unsigned char leaf_global;
void* LeafAddressf8d480::Address() { return &leaf_global; }
