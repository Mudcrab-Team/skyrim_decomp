// Source exposure: binary-analysis; no external implementation source reused.
// Static174e040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e040*);
    virtual void release(Static174e040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e040*);
struct Static174e040 {
    void* value;
    Static174e040();
    ~Static174e040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
