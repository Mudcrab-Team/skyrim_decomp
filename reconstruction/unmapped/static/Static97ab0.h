// Source exposure: binary-analysis
// Static97ab0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97ab0;
extern void construct(Static97ab0*, const Descriptor*);
extern void destroy(Static97ab0*);
struct Static97ab0 {
    void* value;
    Static97ab0() { construct(this, &descriptor); }
    ~Static97ab0() { destroy(this); }
};
