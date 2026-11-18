// Source exposure: binary-analysis
// Static99fb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static99fb0;
extern void construct(Static99fb0*, const Descriptor*);
extern void destroy(Static99fb0*);
struct Static99fb0 {
    void* value;
    Static99fb0() { construct(this, &descriptor); }
    ~Static99fb0() { destroy(this); }
};
