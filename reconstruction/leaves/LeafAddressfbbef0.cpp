// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfbbef0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfbbef0 LeafAddressfbbef0::Address
#include "LeafAddressfbbef0.h"
extern unsigned char leaf_global;
void* LeafAddressfbbef0::Address() { return &leaf_global; }
