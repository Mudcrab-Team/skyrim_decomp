// Source exposure: binary-analysis
// Static21c20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21c20;
extern void construct(Static21c20*, const Descriptor*);
extern void destroy(Static21c20*);
struct Static21c20 {
    void* value;
    Static21c20() { construct(this, &descriptor); }
    ~Static21c20() { destroy(this); }
};
