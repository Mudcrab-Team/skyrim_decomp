// Source exposure: binary-analysis; no external implementation source reused.
// Static1795470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795470*);
    virtual void release(Static1795470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795470*);
struct Static1795470 {
    void* value;
    Static1795470();
    ~Static1795470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
