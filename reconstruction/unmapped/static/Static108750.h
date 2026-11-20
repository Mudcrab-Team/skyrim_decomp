// Source exposure: binary-analysis
// Static108750, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108750;
extern void construct(Static108750*, const Descriptor*);
extern void destroy(Static108750*);
struct Static108750 {
    void* value;
    Static108750() { construct(this, &descriptor); }
    ~Static108750() { destroy(this); }
};
