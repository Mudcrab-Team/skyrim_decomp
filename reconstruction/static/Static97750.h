// Source exposure: binary-analysis
// Static97750, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97750;
extern void construct(Static97750*, const Descriptor*);
extern void destroy(Static97750*);
struct Static97750 {
    void* value;
    Static97750() { construct(this, &descriptor); }
    ~Static97750() { destroy(this); }
};
