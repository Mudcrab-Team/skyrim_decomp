// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb1410, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb1410 LeafAddressfb1410::Address
#include "LeafAddressfb1410.h"
extern unsigned char leaf_global;
void* LeafAddressfb1410::Address() { return &leaf_global; }
