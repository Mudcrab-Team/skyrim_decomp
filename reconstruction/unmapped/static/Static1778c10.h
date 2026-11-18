// Source exposure: binary-analysis; no external implementation source reused.
// Static1778c10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778c10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778c10*);
    virtual void release(Static1778c10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778c10*);
struct Static1778c10 {
    void* value;
    Static1778c10();
    ~Static1778c10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
