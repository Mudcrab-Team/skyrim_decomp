// Source exposure: binary-analysis; no external implementation source reused.
// Static1770600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770600*);
    virtual void release(Static1770600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770600*);
struct Static1770600 {
    void* value;
    Static1770600();
    ~Static1770600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
