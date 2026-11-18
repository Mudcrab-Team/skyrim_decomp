// Source exposure: binary-analysis
// Static97ae0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97ae0;
extern void construct(Static97ae0*, const Descriptor*);
extern void destroy(Static97ae0*);
struct Static97ae0 {
    void* value;
    Static97ae0() { construct(this, &descriptor); }
    ~Static97ae0() { destroy(this); }
};
