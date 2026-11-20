// Source exposure: binary-analysis
// Staticed390, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticed390;
extern void construct(Staticed390*, const Descriptor*);
extern void destroy(Staticed390*);
struct Staticed390 {
    void* value;
    Staticed390() { construct(this, &descriptor); }
    ~Staticed390() { destroy(this); }
};
