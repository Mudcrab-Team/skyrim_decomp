// Source exposure: binary-analysis; no external implementation source reused.
// Static174d040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d040*);
    virtual void release(Static174d040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d040*);
struct Static174d040 {
    void* value;
    Static174d040();
    ~Static174d040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
