// Source exposure: binary-analysis
// Static17300, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static17300;
extern void construct(Static17300*, const Descriptor*);
extern void destroy(Static17300*);
struct Static17300 {
    void* value;
    Static17300() { construct(this, &descriptor); }
    ~Static17300() { destroy(this); }
};
