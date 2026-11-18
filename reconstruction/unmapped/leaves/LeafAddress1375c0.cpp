// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1375c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1375c0 LeafAddress1375c0::Address
#include "LeafAddress1375c0.h"
extern unsigned char leaf_global;
void* LeafAddress1375c0::Address() { return &leaf_global; }
