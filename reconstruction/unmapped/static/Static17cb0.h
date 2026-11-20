// Source exposure: binary-analysis
// Static17cb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static17cb0;
extern void construct(Static17cb0*, const Descriptor*);
extern void destroy(Static17cb0*);
struct Static17cb0 {
    void* value;
    Static17cb0() { construct(this, &descriptor); }
    ~Static17cb0() { destroy(this); }
};
