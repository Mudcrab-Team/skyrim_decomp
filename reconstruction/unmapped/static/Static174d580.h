// Source exposure: binary-analysis; no external implementation source reused.
// Static174d580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d580*);
    virtual void release(Static174d580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d580*);
struct Static174d580 {
    void* value;
    Static174d580();
    ~Static174d580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
