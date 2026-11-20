// Source exposure: binary-analysis
// Static213a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static213a0;
extern void construct(Static213a0*, const Descriptor*);
extern void destroy(Static213a0*);
struct Static213a0 {
    void* value;
    Static213a0() { construct(this, &descriptor); }
    ~Static213a0() { destroy(this); }
};
