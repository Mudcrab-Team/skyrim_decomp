// Source exposure: binary-analysis
// Static180d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static180d0;
extern void construct(Static180d0*, const Descriptor*);
extern void destroy(Static180d0*);
struct Static180d0 {
    void* value;
    Static180d0() { construct(this, &descriptor); }
    ~Static180d0() { destroy(this); }
};
