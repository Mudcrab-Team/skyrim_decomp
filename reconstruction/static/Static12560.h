// Source exposure: binary-analysis
// Static12560, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static12560;
extern void construct(Static12560*, const Descriptor*);
extern void destroy(Static12560*);
struct Static12560 {
    void* value;
    Static12560() { construct(this, &descriptor); }
    ~Static12560() { destroy(this); }
};
