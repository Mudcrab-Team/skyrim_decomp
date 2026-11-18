// Source exposure: binary-analysis
// Static103400, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103400;
extern void construct(Static103400*, const Descriptor*);
extern void destroy(Static103400*);
struct Static103400 {
    void* value;
    Static103400() { construct(this, &descriptor); }
    ~Static103400() { destroy(this); }
};
