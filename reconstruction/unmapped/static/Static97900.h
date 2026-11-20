// Source exposure: binary-analysis
// Static97900, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97900;
extern void construct(Static97900*, const Descriptor*);
extern void destroy(Static97900*);
struct Static97900 {
    void* value;
    Static97900() { construct(this, &descriptor); }
    ~Static97900() { destroy(this); }
};
