// Source exposure: binary-analysis
// Static216d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static216d0;
extern void construct(Static216d0*, const Descriptor*);
extern void destroy(Static216d0*);
struct Static216d0 {
    void* value;
    Static216d0() { construct(this, &descriptor); }
    ~Static216d0() { destroy(this); }
};
