// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133cd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133cd0 LeafAddress133cd0::Address
#include "LeafAddress133cd0.h"
extern unsigned char leaf_global;
void* LeafAddress133cd0::Address() { return &leaf_global; }
