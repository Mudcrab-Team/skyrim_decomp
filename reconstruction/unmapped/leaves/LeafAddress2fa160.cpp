// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa160, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa160 LeafAddress2fa160::Address
#include "LeafAddress2fa160.h"
extern unsigned char leaf_global;
void* LeafAddress2fa160::Address() { return &leaf_global; }
