// Source exposure: binary-analysis
// Static21850, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21850;
extern void construct(Static21850*, const Descriptor*);
extern void destroy(Static21850*);
struct Static21850 {
    void* value;
    Static21850() { construct(this, &descriptor); }
    ~Static21850() { destroy(this); }
};
