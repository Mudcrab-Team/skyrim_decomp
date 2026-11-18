// Source exposure: binary-analysis; no external implementation source reused.
// Static177af10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177af10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177af10*);
    virtual void release(Static177af10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177af10*);
struct Static177af10 {
    void* value;
    Static177af10();
    ~Static177af10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
