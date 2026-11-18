// Source exposure: binary-analysis
// Static97d50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97d50;
extern void construct(Static97d50*, const Descriptor*);
extern void destroy(Static97d50*);
struct Static97d50 {
    void* value;
    Static97d50() { construct(this, &descriptor); }
    ~Static97d50() { destroy(this); }
};
