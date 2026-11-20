// Source exposure: binary-analysis
// Static9eff0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9eff0;
extern void construct(Static9eff0*, const Descriptor*);
extern void destroy(Static9eff0*);
struct Static9eff0 {
    void* value;
    Static9eff0() { construct(this, &descriptor); }
    ~Static9eff0() { destroy(this); }
};
