// Source exposure: binary-analysis
// Static253e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static253e0;
extern void construct(Static253e0*, const Descriptor*);
extern void destroy(Static253e0*);
struct Static253e0 {
    void* value;
    Static253e0() { construct(this, &descriptor); }
    ~Static253e0() { destroy(this); }
};
