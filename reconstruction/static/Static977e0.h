// Source exposure: binary-analysis
// Static977e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static977e0;
extern void construct(Static977e0*, const Descriptor*);
extern void destroy(Static977e0*);
struct Static977e0 {
    void* value;
    Static977e0() { construct(this, &descriptor); }
    ~Static977e0() { destroy(this); }
};
