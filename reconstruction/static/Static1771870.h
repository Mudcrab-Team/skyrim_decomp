// Source exposure: binary-analysis; no external implementation source reused.
// Static1771870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771870*);
    virtual void release(Static1771870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771870*);
struct Static1771870 {
    void* value;
    Static1771870();
    ~Static1771870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
