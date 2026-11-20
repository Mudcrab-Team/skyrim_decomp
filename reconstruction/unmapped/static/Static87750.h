// Source exposure: binary-analysis
// Static87750, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static87750;
extern void construct(Static87750*, const Descriptor*);
extern void destroy(Static87750*);
struct Static87750 {
    void* value;
    Static87750() { construct(this, &descriptor); }
    ~Static87750() { destroy(this); }
};
