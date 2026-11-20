// Source exposure: binary-analysis
// Static9f080, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f080;
extern void construct(Static9f080*, const Descriptor*);
extern void destroy(Static9f080*);
struct Static9f080 {
    void* value;
    Static9f080() { construct(this, &descriptor); }
    ~Static9f080() { destroy(this); }
};
