// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb23d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb23d0 LeafAddressfb23d0::Address
#include "LeafAddressfb23d0.h"
extern unsigned char leaf_global;
void* LeafAddressfb23d0::Address() { return &leaf_global; }
