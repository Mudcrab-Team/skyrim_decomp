// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3cc710, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3cc710 LeafAddress3cc710::Address
#include "LeafAddress3cc710.h"
extern unsigned char leaf_global;
void* LeafAddress3cc710::Address() { return &leaf_global; }
