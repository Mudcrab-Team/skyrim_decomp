// Source exposure: binary-analysis
// Static9eed0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9eed0;
extern void construct(Static9eed0*, const Descriptor*);
extern void destroy(Static9eed0*);
struct Static9eed0 {
    void* value;
    Static9eed0() { construct(this, &descriptor); }
    ~Static9eed0() { destroy(this); }
};
