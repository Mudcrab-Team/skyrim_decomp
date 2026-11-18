// Source exposure: binary-analysis
// Static213d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static213d0;
extern void construct(Static213d0*, const Descriptor*);
extern void destroy(Static213d0*);
struct Static213d0 {
    void* value;
    Static213d0() { construct(this, &descriptor); }
    ~Static213d0() { destroy(this); }
};
