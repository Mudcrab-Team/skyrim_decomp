// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress109ea10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x109ea10 LeafAddress109ea10::Address
#include "LeafAddress109ea10.h"
extern unsigned char leaf_global;
void* LeafAddress109ea10::Address() { return &leaf_global; }
