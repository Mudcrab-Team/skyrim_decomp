// Source exposure: binary-analysis
// Static185d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static185d0;
extern void construct(Static185d0*, const Descriptor*);
extern void destroy(Static185d0*);
struct Static185d0 {
    void* value;
    Static185d0() { construct(this, &descriptor); }
    ~Static185d0() { destroy(this); }
};
