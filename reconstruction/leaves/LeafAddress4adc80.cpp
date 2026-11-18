// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4adc80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4adc80 LeafAddress4adc80::Address
#include "LeafAddress4adc80.h"
extern unsigned char leaf_global;
void* LeafAddress4adc80::Address() { return &leaf_global; }
