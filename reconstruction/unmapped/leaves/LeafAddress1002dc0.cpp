// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1002dc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1002dc0 LeafAddress1002dc0::Address
#include "LeafAddress1002dc0.h"
extern unsigned char leaf_global;
void* LeafAddress1002dc0::Address() { return &leaf_global; }
