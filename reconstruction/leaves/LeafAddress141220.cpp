// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress141220, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x141220 LeafAddress141220::Address
#include "LeafAddress141220.h"
extern unsigned char leaf_global;
void* LeafAddress141220::Address() { return &leaf_global; }
