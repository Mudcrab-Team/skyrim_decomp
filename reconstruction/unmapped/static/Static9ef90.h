// Source exposure: binary-analysis
// Static9ef90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ef90;
extern void construct(Static9ef90*, const Descriptor*);
extern void destroy(Static9ef90*);
struct Static9ef90 {
    void* value;
    Static9ef90() { construct(this, &descriptor); }
    ~Static9ef90() { destroy(this); }
};
