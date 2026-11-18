// Source exposure: binary-analysis
// Static14fb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14fb0;
extern void construct(Static14fb0*, const Descriptor*);
extern void destroy(Static14fb0*);
struct Static14fb0 {
    void* value;
    Static14fb0() { construct(this, &descriptor); }
    ~Static14fb0() { destroy(this); }
};
