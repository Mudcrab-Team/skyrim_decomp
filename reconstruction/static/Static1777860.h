// Source exposure: binary-analysis; no external implementation source reused.
// Static1777860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777860*);
    virtual void release(Static1777860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777860*);
struct Static1777860 {
    void* value;
    Static1777860();
    ~Static1777860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
