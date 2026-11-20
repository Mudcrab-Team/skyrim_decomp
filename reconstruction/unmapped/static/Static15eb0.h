// Source exposure: binary-analysis
// Static15eb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15eb0;
extern void construct(Static15eb0*, const Descriptor*);
extern void destroy(Static15eb0*);
struct Static15eb0 {
    void* value;
    Static15eb0() { construct(this, &descriptor); }
    ~Static15eb0() { destroy(this); }
};
