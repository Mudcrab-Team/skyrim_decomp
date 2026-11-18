// Source exposure: binary-analysis
// Static9ae40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ae40;
extern void construct(Static9ae40*, const Descriptor*);
extern void destroy(Static9ae40*);
struct Static9ae40 {
    void* value;
    Static9ae40() { construct(this, &descriptor); }
    ~Static9ae40() { destroy(this); }
};
