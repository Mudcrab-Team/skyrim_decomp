// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf77e10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf77e10 LeafAddressf77e10::Address
#include "LeafAddressf77e10.h"
extern unsigned char leaf_global;
void* LeafAddressf77e10::Address() { return &leaf_global; }
