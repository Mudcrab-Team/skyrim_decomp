// Source exposure: binary-analysis
// Static9fdc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fdc0;
extern void construct(Static9fdc0*, const Descriptor*);
extern void destroy(Static9fdc0*);
struct Static9fdc0 {
    void* value;
    Static9fdc0() { construct(this, &descriptor); }
    ~Static9fdc0() { destroy(this); }
};
