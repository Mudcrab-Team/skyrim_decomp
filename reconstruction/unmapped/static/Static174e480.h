// Source exposure: binary-analysis; no external implementation source reused.
// Static174e480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e480*);
    virtual void release(Static174e480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e480*);
struct Static174e480 {
    void* value;
    Static174e480();
    ~Static174e480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
