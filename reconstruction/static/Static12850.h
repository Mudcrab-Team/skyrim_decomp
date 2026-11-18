// Source exposure: binary-analysis
// Static12850, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static12850;
extern void construct(Static12850*, const Descriptor*);
extern void destroy(Static12850*);
struct Static12850 {
    void* value;
    Static12850() { construct(this, &descriptor); }
    ~Static12850() { destroy(this); }
};
