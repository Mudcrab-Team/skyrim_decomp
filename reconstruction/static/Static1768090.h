// Source exposure: binary-analysis; no external implementation source reused.
// Static1768090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768090*);
    virtual void release(Static1768090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768090*);
struct Static1768090 {
    void* value;
    Static1768090();
    ~Static1768090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
