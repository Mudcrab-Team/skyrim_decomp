// Source exposure: binary-analysis
// Static97c60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97c60;
extern void construct(Static97c60*, const Descriptor*);
extern void destroy(Static97c60*);
struct Static97c60 {
    void* value;
    Static97c60() { construct(this, &descriptor); }
    ~Static97c60() { destroy(this); }
};
