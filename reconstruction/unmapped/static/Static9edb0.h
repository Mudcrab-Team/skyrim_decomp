// Source exposure: binary-analysis
// Static9edb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9edb0;
extern void construct(Static9edb0*, const Descriptor*);
extern void destroy(Static9edb0*);
struct Static9edb0 {
    void* value;
    Static9edb0() { construct(this, &descriptor); }
    ~Static9edb0() { destroy(this); }
};
