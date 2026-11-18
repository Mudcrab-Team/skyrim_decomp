// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1290ff0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1290ff0 LeafAddress1290ff0::Address
#include "LeafAddress1290ff0.h"
extern unsigned char leaf_global;
void* LeafAddress1290ff0::Address() { return &leaf_global; }
