// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf24780, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf24780 LeafAddressf24780::Address
#include "LeafAddressf24780.h"
extern unsigned char leaf_global;
void* LeafAddressf24780::Address() { return &leaf_global; }
