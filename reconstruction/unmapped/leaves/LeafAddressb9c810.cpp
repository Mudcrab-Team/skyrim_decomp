// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c810, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c810 LeafAddressb9c810::Address
#include "LeafAddressb9c810.h"
extern unsigned char leaf_global;
void* LeafAddressb9c810::Address() { return &leaf_global; }
