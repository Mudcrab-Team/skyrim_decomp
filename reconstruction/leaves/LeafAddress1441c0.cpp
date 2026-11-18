// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1441c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1441c0 LeafAddress1441c0::Address
#include "LeafAddress1441c0.h"
extern unsigned char leaf_global;
void* LeafAddress1441c0::Address() { return &leaf_global; }
