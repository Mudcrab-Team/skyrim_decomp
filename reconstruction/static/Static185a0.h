// Source exposure: binary-analysis
// Static185a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static185a0;
extern void construct(Static185a0*, const Descriptor*);
extern void destroy(Static185a0*);
struct Static185a0 {
    void* value;
    Static185a0() { construct(this, &descriptor); }
    ~Static185a0() { destroy(this); }
};
