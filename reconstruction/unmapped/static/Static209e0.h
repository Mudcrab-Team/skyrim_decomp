// Source exposure: binary-analysis
// Static209e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static209e0;
extern void construct(Static209e0*, const Descriptor*);
extern void destroy(Static209e0*);
struct Static209e0 {
    void* value;
    Static209e0() { construct(this, &descriptor); }
    ~Static209e0() { destroy(this); }
};
