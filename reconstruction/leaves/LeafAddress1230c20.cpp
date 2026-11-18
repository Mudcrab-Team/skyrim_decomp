// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1230c20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1230c20 LeafAddress1230c20::Address
#include "LeafAddress1230c20.h"
extern unsigned char leaf_global;
void* LeafAddress1230c20::Address() { return &leaf_global; }
