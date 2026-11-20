// Source exposure: binary-analysis
// Static9eab0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9eab0;
extern void construct(Static9eab0*, const Descriptor*);
extern void destroy(Static9eab0*);
struct Static9eab0 {
    void* value;
    Static9eab0() { construct(this, &descriptor); }
    ~Static9eab0() { destroy(this); }
};
