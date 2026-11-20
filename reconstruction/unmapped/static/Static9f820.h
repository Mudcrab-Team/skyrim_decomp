// Source exposure: binary-analysis
// Static9f820, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f820;
extern void construct(Static9f820*, const Descriptor*);
extern void destroy(Static9f820*);
struct Static9f820 {
    void* value;
    Static9f820() { construct(this, &descriptor); }
    ~Static9f820() { destroy(this); }
};
