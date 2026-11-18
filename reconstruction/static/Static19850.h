// Source exposure: binary-analysis
// Static19850, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static19850;
extern void construct(Static19850*, const Descriptor*);
extern void destroy(Static19850*);
struct Static19850 {
    void* value;
    Static19850() { construct(this, &descriptor); }
    ~Static19850() { destroy(this); }
};
