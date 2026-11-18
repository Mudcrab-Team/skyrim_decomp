// Source exposure: binary-analysis
// Static158e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static158e0;
extern void construct(Static158e0*, const Descriptor*);
extern void destroy(Static158e0*);
struct Static158e0 {
    void* value;
    Static158e0() { construct(this, &descriptor); }
    ~Static158e0() { destroy(this); }
};
