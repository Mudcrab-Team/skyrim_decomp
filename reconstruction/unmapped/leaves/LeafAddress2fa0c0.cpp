// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa0c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa0c0 LeafAddress2fa0c0::Address
#include "LeafAddress2fa0c0.h"
extern unsigned char leaf_global;
void* LeafAddress2fa0c0::Address() { return &leaf_global; }
