// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress468270, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x468270 LeafAddress468270::Address
#include "LeafAddress468270.h"
extern unsigned char leaf_global;
void* LeafAddress468270::Address() { return &leaf_global; }
