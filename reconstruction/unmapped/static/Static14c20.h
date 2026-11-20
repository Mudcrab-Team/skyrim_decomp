// Source exposure: binary-analysis
// Static14c20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14c20;
extern void construct(Static14c20*, const Descriptor*);
extern void destroy(Static14c20*);
struct Static14c20 {
    void* value;
    Static14c20() { construct(this, &descriptor); }
    ~Static14c20() { destroy(this); }
};
