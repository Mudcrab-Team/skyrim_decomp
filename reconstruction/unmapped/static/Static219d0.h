// Source exposure: binary-analysis
// Static219d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static219d0;
extern void construct(Static219d0*, const Descriptor*);
extern void destroy(Static219d0*);
struct Static219d0 {
    void* value;
    Static219d0() { construct(this, &descriptor); }
    ~Static219d0() { destroy(this); }
};
