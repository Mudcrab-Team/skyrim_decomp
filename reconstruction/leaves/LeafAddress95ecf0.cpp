// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress95ecf0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x95ecf0 LeafAddress95ecf0::Address
#include "LeafAddress95ecf0.h"
extern unsigned char leaf_global;
void* LeafAddress95ecf0::Address() { return &leaf_global; }
