// Source exposure: binary-analysis
// Static9ede0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ede0;
extern void construct(Static9ede0*, const Descriptor*);
extern void destroy(Static9ede0*);
struct Static9ede0 {
    void* value;
    Static9ede0() { construct(this, &descriptor); }
    ~Static9ede0() { destroy(this); }
};
