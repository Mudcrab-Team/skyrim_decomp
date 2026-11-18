// Source exposure: binary-analysis; no external implementation source reused.
// Static1795b30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795b30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795b30*);
    virtual void release(Static1795b30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795b30*);
struct Static1795b30 {
    void* value;
    Static1795b30();
    ~Static1795b30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
