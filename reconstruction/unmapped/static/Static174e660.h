// Source exposure: binary-analysis; no external implementation source reused.
// Static174e660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e660*);
    virtual void release(Static174e660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e660*);
struct Static174e660 {
    void* value;
    Static174e660();
    ~Static174e660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
