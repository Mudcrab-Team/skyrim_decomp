// Source exposure: binary-analysis
// Static922a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static922a0;
extern void construct(Static922a0*, const Descriptor*);
extern void destroy(Static922a0*);
struct Static922a0 {
    void* value;
    Static922a0() { construct(this, &descriptor); }
    ~Static922a0() { destroy(this); }
};
