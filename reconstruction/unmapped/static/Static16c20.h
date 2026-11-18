// Source exposure: binary-analysis
// Static16c20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static16c20;
extern void construct(Static16c20*, const Descriptor*);
extern void destroy(Static16c20*);
struct Static16c20 {
    void* value;
    Static16c20() { construct(this, &descriptor); }
    ~Static16c20() { destroy(this); }
};
