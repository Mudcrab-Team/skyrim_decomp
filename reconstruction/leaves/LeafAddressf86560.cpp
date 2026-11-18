// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf86560, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf86560 LeafAddressf86560::Address
#include "LeafAddressf86560.h"
extern unsigned char leaf_global;
void* LeafAddressf86560::Address() { return &leaf_global; }
