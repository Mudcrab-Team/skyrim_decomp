// Source exposure: binary-analysis
// Static97c00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97c00;
extern void construct(Static97c00*, const Descriptor*);
extern void destroy(Static97c00*);
struct Static97c00 {
    void* value;
    Static97c00() { construct(this, &descriptor); }
    ~Static97c00() { destroy(this); }
};
