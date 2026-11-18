// Source exposure: binary-analysis
// Static21a60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21a60;
extern void construct(Static21a60*, const Descriptor*);
extern void destroy(Static21a60*);
struct Static21a60 {
    void* value;
    Static21a60() { construct(this, &descriptor); }
    ~Static21a60() { destroy(this); }
};
