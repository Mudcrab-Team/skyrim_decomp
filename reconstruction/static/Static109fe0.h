// Source exposure: binary-analysis
// Static109fe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109fe0;
extern void construct(Static109fe0*, const Descriptor*);
extern void destroy(Static109fe0*);
struct Static109fe0 {
    void* value;
    Static109fe0() { construct(this, &descriptor); }
    ~Static109fe0() { destroy(this); }
};
