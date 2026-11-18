// Source exposure: binary-analysis
// Static199d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static199d0;
extern void construct(Static199d0*, const Descriptor*);
extern void destroy(Static199d0*);
struct Static199d0 {
    void* value;
    Static199d0() { construct(this, &descriptor); }
    ~Static199d0() { destroy(this); }
};
