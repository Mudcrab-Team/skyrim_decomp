// Source exposure: binary-analysis
// Static9f970, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f970;
extern void construct(Static9f970*, const Descriptor*);
extern void destroy(Static9f970*);
struct Static9f970 {
    void* value;
    Static9f970() { construct(this, &descriptor); }
    ~Static9f970() { destroy(this); }
};
