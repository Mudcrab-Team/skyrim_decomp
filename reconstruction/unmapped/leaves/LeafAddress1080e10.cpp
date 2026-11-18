// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1080e10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1080e10 LeafAddress1080e10::Address
#include "LeafAddress1080e10.h"
extern unsigned char leaf_global;
void* LeafAddress1080e10::Address() { return &leaf_global; }
