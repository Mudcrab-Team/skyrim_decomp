// Source exposure: binary-analysis
// Static9e900, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e900;
extern void construct(Static9e900*, const Descriptor*);
extern void destroy(Static9e900*);
struct Static9e900 {
    void* value;
    Static9e900() { construct(this, &descriptor); }
    ~Static9e900() { destroy(this); }
};
