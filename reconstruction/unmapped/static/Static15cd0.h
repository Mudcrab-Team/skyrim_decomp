// Source exposure: binary-analysis
// Static15cd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15cd0;
extern void construct(Static15cd0*, const Descriptor*);
extern void destroy(Static15cd0*);
struct Static15cd0 {
    void* value;
    Static15cd0() { construct(this, &descriptor); }
    ~Static15cd0() { destroy(this); }
};
