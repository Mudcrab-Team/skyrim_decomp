// Source exposure: binary-analysis
// Static154f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static154f0;
extern void construct(Static154f0*, const Descriptor*);
extern void destroy(Static154f0*);
struct Static154f0 {
    void* value;
    Static154f0() { construct(this, &descriptor); }
    ~Static154f0() { destroy(this); }
};
