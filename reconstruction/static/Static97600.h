// Source exposure: binary-analysis
// Static97600, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97600;
extern void construct(Static97600*, const Descriptor*);
extern void destroy(Static97600*);
struct Static97600 {
    void* value;
    Static97600() { construct(this, &descriptor); }
    ~Static97600() { destroy(this); }
};
