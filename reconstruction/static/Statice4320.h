// Source exposure: binary-analysis
// Statice4320, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice4320;
extern void construct(Statice4320*, const Descriptor*);
extern void destroy(Statice4320*);
struct Statice4320 {
    void* value;
    Statice4320() { construct(this, &descriptor); }
    ~Statice4320() { destroy(this); }
};
