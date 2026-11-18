// Source exposure: binary-analysis
// Static87680, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static87680;
extern void construct(Static87680*, const Descriptor*);
extern void destroy(Static87680*);
struct Static87680 {
    void* value;
    Static87680() { construct(this, &descriptor); }
    ~Static87680() { destroy(this); }
};
