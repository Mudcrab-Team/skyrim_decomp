// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49620, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49620 LeafAddressc49620::Address
#include "LeafAddressc49620.h"
extern unsigned char leaf_global;
void* LeafAddressc49620::Address() { return &leaf_global; }
