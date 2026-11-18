// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa100, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa100 LeafAddress2fa100::Address
#include "LeafAddress2fa100.h"
extern unsigned char leaf_global;
void* LeafAddress2fa100::Address() { return &leaf_global; }
