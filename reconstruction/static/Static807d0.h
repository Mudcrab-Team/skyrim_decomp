// Source exposure: binary-analysis
// Static807d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static807d0;
extern void construct(Static807d0*, const Descriptor*);
extern void destroy(Static807d0*);
struct Static807d0 {
    void* value;
    Static807d0() { construct(this, &descriptor); }
    ~Static807d0() { destroy(this); }
};
