// Source exposure: binary-analysis
// Static15fa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15fa0;
extern void construct(Static15fa0*, const Descriptor*);
extern void destroy(Static15fa0*);
struct Static15fa0 {
    void* value;
    Static15fa0() { construct(this, &descriptor); }
    ~Static15fa0() { destroy(this); }
};
