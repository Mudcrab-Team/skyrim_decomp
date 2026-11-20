// Source exposure: binary-analysis; no external implementation source reused.
// Static1780870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780870*);
    virtual void release(Static1780870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780870*);
struct Static1780870 {
    void* value;
    Static1780870();
    ~Static1780870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
