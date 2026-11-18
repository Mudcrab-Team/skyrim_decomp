// Source exposure: binary-analysis
// Static103190, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103190;
extern void construct(Static103190*, const Descriptor*);
extern void destroy(Static103190*);
struct Static103190 {
    void* value;
    Static103190() { construct(this, &descriptor); }
    ~Static103190() { destroy(this); }
};
