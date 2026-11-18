// Source exposure: binary-analysis
// Static81eb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static81eb0;
extern void construct(Static81eb0*, const Descriptor*);
extern void destroy(Static81eb0*);
struct Static81eb0 {
    void* value;
    Static81eb0() { construct(this, &descriptor); }
    ~Static81eb0() { destroy(this); }
};
