// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfbfa30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfbfa30 LeafAddressfbfa30::Address
#include "LeafAddressfbfa30.h"
extern unsigned char leaf_global;
void* LeafAddressfbfa30::Address() { return &leaf_global; }
