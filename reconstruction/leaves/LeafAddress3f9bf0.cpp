// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3f9bf0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3f9bf0 LeafAddress3f9bf0::Address
#include "LeafAddress3f9bf0.h"
extern unsigned char leaf_global;
void* LeafAddress3f9bf0::Address() { return &leaf_global; }
