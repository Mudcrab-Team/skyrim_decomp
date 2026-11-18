// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress203b10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x203b10 LeafAddress203b10::Address
#include "LeafAddress203b10.h"
extern unsigned char leaf_global;
void* LeafAddress203b10::Address() { return &leaf_global; }
