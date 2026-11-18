// Source exposure: binary-analysis
// Static12880, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static12880;
extern void construct(Static12880*, const Descriptor*);
extern void destroy(Static12880*);
struct Static12880 {
    void* value;
    Static12880() { construct(this, &descriptor); }
    ~Static12880() { destroy(this); }
};
