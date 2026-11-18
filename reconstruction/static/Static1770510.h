// Source exposure: binary-analysis; no external implementation source reused.
// Static1770510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770510*);
    virtual void release(Static1770510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770510*);
struct Static1770510 {
    void* value;
    Static1770510();
    ~Static1770510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
