// Source exposure: binary-analysis
// Static9ebd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ebd0;
extern void construct(Static9ebd0*, const Descriptor*);
extern void destroy(Static9ebd0*);
struct Static9ebd0 {
    void* value;
    Static9ebd0() { construct(this, &descriptor); }
    ~Static9ebd0() { destroy(this); }
};
