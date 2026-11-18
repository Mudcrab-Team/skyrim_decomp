// Source exposure: binary-analysis
// Static109da0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109da0;
extern void construct(Static109da0*, const Descriptor*);
extern void destroy(Static109da0*);
struct Static109da0 {
    void* value;
    Static109da0() { construct(this, &descriptor); }
    ~Static109da0() { destroy(this); }
};
