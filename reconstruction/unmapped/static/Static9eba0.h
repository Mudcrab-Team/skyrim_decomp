// Source exposure: binary-analysis
// Static9eba0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9eba0;
extern void construct(Static9eba0*, const Descriptor*);
extern void destroy(Static9eba0*);
struct Static9eba0 {
    void* value;
    Static9eba0() { construct(this, &descriptor); }
    ~Static9eba0() { destroy(this); }
};
