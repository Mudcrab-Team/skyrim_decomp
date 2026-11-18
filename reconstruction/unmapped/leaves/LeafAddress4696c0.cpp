// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4696c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4696c0 LeafAddress4696c0::Address
#include "LeafAddress4696c0.h"
extern unsigned char leaf_global;
void* LeafAddress4696c0::Address() { return &leaf_global; }
