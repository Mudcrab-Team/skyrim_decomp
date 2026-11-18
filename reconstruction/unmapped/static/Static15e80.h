// Source exposure: binary-analysis
// Static15e80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15e80;
extern void construct(Static15e80*, const Descriptor*);
extern void destroy(Static15e80*);
struct Static15e80 {
    void* value;
    Static15e80() { construct(this, &descriptor); }
    ~Static15e80() { destroy(this); }
};
