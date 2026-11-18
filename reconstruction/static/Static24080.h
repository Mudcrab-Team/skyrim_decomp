// Source exposure: binary-analysis
// Static24080, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24080;
extern void construct(Static24080*, const Descriptor*);
extern void destroy(Static24080*);
struct Static24080 {
    void* value;
    Static24080() { construct(this, &descriptor); }
    ~Static24080() { destroy(this); }
};
