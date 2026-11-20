// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress392e00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x392e00 LeafAddress392e00::Address
#include "LeafAddress392e00.h"
extern unsigned char leaf_global;
void* LeafAddress392e00::Address() { return &leaf_global; }
