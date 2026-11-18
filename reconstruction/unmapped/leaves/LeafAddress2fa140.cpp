// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2fa140, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2fa140 LeafAddress2fa140::Address
#include "LeafAddress2fa140.h"
extern unsigned char leaf_global;
void* LeafAddress2fa140::Address() { return &leaf_global; }
