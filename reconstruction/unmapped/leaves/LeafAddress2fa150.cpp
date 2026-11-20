// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa150, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa150 LeafAddress2fa150::Address
#include "LeafAddress2fa150.h"
extern unsigned char leaf_global;
void* LeafAddress2fa150::Address() { return &leaf_global; }
