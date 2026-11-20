// Source exposure: binary-analysis
// Static977b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static977b0;
extern void construct(Static977b0*, const Descriptor*);
extern void destroy(Static977b0*);
struct Static977b0 {
    void* value;
    Static977b0() { construct(this, &descriptor); }
    ~Static977b0() { destroy(this); }
};
