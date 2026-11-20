// Source exposure: binary-analysis; no external implementation source reused.
// Static1786090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786090*);
    virtual void release(Static1786090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786090*);
struct Static1786090 {
    void* value;
    Static1786090();
    ~Static1786090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
