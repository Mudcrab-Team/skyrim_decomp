// Source exposure: binary-analysis
// Static9b390, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9b390;
extern void construct(Static9b390*, const Descriptor*);
extern void destroy(Static9b390*);
struct Static9b390 {
    void* value;
    Static9b390() { construct(this, &descriptor); }
    ~Static9b390() { destroy(this); }
};
