// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa170, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa170 LeafAddress2fa170::Address
#include "LeafAddress2fa170.h"
extern unsigned char leaf_global;
void* LeafAddress2fa170::Address() { return &leaf_global; }
