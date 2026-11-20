// Source exposure: binary-analysis; no external implementation source reused.
// Static174d850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d850*);
    virtual void release(Static174d850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d850*);
struct Static174d850 {
    void* value;
    Static174d850();
    ~Static174d850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
