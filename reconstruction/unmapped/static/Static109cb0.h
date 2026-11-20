// Source exposure: binary-analysis
// Static109cb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109cb0;
extern void construct(Static109cb0*, const Descriptor*);
extern void destroy(Static109cb0*);
struct Static109cb0 {
    void* value;
    Static109cb0() { construct(this, &descriptor); }
    ~Static109cb0() { destroy(this); }
};
