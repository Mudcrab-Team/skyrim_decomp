// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1080e20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1080e20 LeafAddress1080e20::Address
#include "LeafAddress1080e20.h"
extern unsigned char leaf_global;
void* LeafAddress1080e20::Address() { return &leaf_global; }
