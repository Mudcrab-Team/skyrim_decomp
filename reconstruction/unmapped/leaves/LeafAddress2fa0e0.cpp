// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa0e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa0e0 LeafAddress2fa0e0::Address
#include "LeafAddress2fa0e0.h"
extern unsigned char leaf_global;
void* LeafAddress2fa0e0::Address() { return &leaf_global; }
