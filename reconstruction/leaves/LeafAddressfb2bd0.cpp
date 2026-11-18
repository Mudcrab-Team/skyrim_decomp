// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb2bd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb2bd0 LeafAddressfb2bd0::Address
#include "LeafAddressfb2bd0.h"
extern unsigned char leaf_global;
void* LeafAddressfb2bd0::Address() { return &leaf_global; }
