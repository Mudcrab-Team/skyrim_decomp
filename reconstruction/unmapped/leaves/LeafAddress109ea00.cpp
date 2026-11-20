// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress109ea00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x109ea00 LeafAddress109ea00::Address
#include "LeafAddress109ea00.h"
extern unsigned char leaf_global;
void* LeafAddress109ea00::Address() { return &leaf_global; }
