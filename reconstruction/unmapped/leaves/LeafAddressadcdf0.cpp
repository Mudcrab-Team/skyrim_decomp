// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadcdf0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadcdf0 LeafAddressadcdf0::Address
#include "LeafAddressadcdf0.h"
extern unsigned char leaf_global;
void* LeafAddressadcdf0::Address() { return &leaf_global; }
