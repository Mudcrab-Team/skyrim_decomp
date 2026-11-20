// Source exposure: binary-analysis
// Static81ee0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static81ee0;
extern void construct(Static81ee0*, const Descriptor*);
extern void destroy(Static81ee0*);
struct Static81ee0 {
    void* value;
    Static81ee0() { construct(this, &descriptor); }
    ~Static81ee0() { destroy(this); }
};
