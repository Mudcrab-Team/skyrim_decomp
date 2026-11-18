// Source exposure: binary-analysis; no external implementation source reused.
// Static174df00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174df00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174df00*);
    virtual void release(Static174df00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174df00*);
struct Static174df00 {
    void* value;
    Static174df00();
    ~Static174df00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
