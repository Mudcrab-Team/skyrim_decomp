// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa110, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa110 LeafAddress2fa110::Address
#include "LeafAddress2fa110.h"
extern unsigned char leaf_global;
void* LeafAddress2fa110::Address() { return &leaf_global; }
