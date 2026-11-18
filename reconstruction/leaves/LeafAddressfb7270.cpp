// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb7270, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb7270 LeafAddressfb7270::Address
#include "LeafAddressfb7270.h"
extern unsigned char leaf_global;
void* LeafAddressfb7270::Address() { return &leaf_global; }
