// Source exposure: binary-analysis
// Static109bc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109bc0;
extern void construct(Static109bc0*, const Descriptor*);
extern void destroy(Static109bc0*);
struct Static109bc0 {
    void* value;
    Static109bc0() { construct(this, &descriptor); }
    ~Static109bc0() { destroy(this); }
};
