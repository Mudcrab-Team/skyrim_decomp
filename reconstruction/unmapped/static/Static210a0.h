// Source exposure: binary-analysis
// Static210a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static210a0;
extern void construct(Static210a0*, const Descriptor*);
extern void destroy(Static210a0*);
struct Static210a0 {
    void* value;
    Static210a0() { construct(this, &descriptor); }
    ~Static210a0() { destroy(this); }
};
