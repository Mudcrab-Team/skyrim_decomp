// Source exposure: binary-analysis
// Statice5410, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice5410;
extern void construct(Statice5410*, const Descriptor*);
extern void destroy(Statice5410*);
struct Statice5410 {
    void* value;
    Statice5410() { construct(this, &descriptor); }
    ~Statice5410() { destroy(this); }
};
