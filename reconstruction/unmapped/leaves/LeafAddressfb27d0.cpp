// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb27d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb27d0 LeafAddressfb27d0::Address
#include "LeafAddressfb27d0.h"
extern unsigned char leaf_global;
void* LeafAddressfb27d0::Address() { return &leaf_global; }
