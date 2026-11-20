// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb90c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb90c0 LeafAddressfb90c0::Address
#include "LeafAddressfb90c0.h"
extern unsigned char leaf_global;
void* LeafAddressfb90c0::Address() { return &leaf_global; }
