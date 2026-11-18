// Source exposure: binary-analysis
// Static240e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static240e0;
extern void construct(Static240e0*, const Descriptor*);
extern void destroy(Static240e0*);
struct Static240e0 {
    void* value;
    Static240e0() { construct(this, &descriptor); }
    ~Static240e0() { destroy(this); }
};
