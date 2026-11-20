// Source exposure: binary-analysis
// Static102da0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static102da0;
extern void construct(Static102da0*, const Descriptor*);
extern void destroy(Static102da0*);
struct Static102da0 {
    void* value;
    Static102da0() { construct(this, &descriptor); }
    ~Static102da0() { destroy(this); }
};
