// Source exposure: binary-analysis
// Static23ea0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23ea0;
extern void construct(Static23ea0*, const Descriptor*);
extern void destroy(Static23ea0*);
struct Static23ea0 {
    void* value;
    Static23ea0() { construct(this, &descriptor); }
    ~Static23ea0() { destroy(this); }
};
