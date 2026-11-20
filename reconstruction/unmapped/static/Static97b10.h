// Source exposure: binary-analysis
// Static97b10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97b10;
extern void construct(Static97b10*, const Descriptor*);
extern void destroy(Static97b10*);
struct Static97b10 {
    void* value;
    Static97b10() { construct(this, &descriptor); }
    ~Static97b10() { destroy(this); }
};
