// Source exposure: binary-analysis; no external implementation source reused.
// Static1754090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754090*);
    virtual void release(Static1754090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754090*);
struct Static1754090 {
    void* value;
    Static1754090();
    ~Static1754090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
