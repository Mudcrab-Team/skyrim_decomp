// Source exposure: binary-analysis
// Static97690, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97690;
extern void construct(Static97690*, const Descriptor*);
extern void destroy(Static97690*);
struct Static97690 {
    void* value;
    Static97690() { construct(this, &descriptor); }
    ~Static97690() { destroy(this); }
};
