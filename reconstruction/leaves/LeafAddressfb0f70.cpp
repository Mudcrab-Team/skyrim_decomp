// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb0f70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb0f70 LeafAddressfb0f70::Address
#include "LeafAddressfb0f70.h"
extern unsigned char leaf_global;
void* LeafAddressfb0f70::Address() { return &leaf_global; }
