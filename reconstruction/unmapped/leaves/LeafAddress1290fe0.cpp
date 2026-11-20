// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1290fe0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1290fe0 LeafAddress1290fe0::Address
#include "LeafAddress1290fe0.h"
extern unsigned char leaf_global;
void* LeafAddress1290fe0::Address() { return &leaf_global; }
