// Source exposure: binary-analysis
// Static88f30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static88f30;
extern void construct(Static88f30*, const Descriptor*);
extern void destroy(Static88f30*);
struct Static88f30 {
    void* value;
    Static88f30() { construct(this, &descriptor); }
    ~Static88f30() { destroy(this); }
};
