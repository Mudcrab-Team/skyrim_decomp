// Source exposure: binary-analysis
// Static87af0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static87af0;
extern void construct(Static87af0*, const Descriptor*);
extern void destroy(Static87af0*);
struct Static87af0 {
    void* value;
    Static87af0() { construct(this, &descriptor); }
    ~Static87af0() { destroy(this); }
};
