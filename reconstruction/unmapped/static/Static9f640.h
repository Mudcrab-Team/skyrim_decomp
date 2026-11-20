// Source exposure: binary-analysis
// Static9f640, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f640;
extern void construct(Static9f640*, const Descriptor*);
extern void destroy(Static9f640*);
struct Static9f640 {
    void* value;
    Static9f640() { construct(this, &descriptor); }
    ~Static9f640() { destroy(this); }
};
