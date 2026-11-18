// Source exposure: binary-analysis; no external implementation source reused.
// Static174e840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e840*);
    virtual void release(Static174e840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e840*);
struct Static174e840 {
    void* value;
    Static174e840();
    ~Static174e840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
