// Source exposure: binary-analysis
// Static97780, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97780;
extern void construct(Static97780*, const Descriptor*);
extern void destroy(Static97780*);
struct Static97780 {
    void* value;
    Static97780() { construct(this, &descriptor); }
    ~Static97780() { destroy(this); }
};
