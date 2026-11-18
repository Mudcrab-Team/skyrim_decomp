// Source exposure: binary-analysis; no external implementation source reused.
// Static1777e50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777e50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777e50*);
    virtual void release(Static1777e50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777e50*);
struct Static1777e50 {
    void* value;
    Static1777e50();
    ~Static1777e50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
