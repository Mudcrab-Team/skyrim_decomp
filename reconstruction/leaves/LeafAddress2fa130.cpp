// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa130, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa130 LeafAddress2fa130::Address
#include "LeafAddress2fa130.h"
extern unsigned char leaf_global;
void* LeafAddress2fa130::Address() { return &leaf_global; }
