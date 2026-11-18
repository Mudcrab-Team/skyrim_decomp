// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa120, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa120 LeafAddress2fa120::Address
#include "LeafAddress2fa120.h"
extern unsigned char leaf_global;
void* LeafAddress2fa120::Address() { return &leaf_global; }
