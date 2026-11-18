// Source exposure: binary-analysis; no external implementation source reused.
// Static1780aa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780aa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780aa0*);
    virtual void release(Static1780aa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780aa0*);
struct Static1780aa0 {
    void* value;
    Static1780aa0();
    ~Static1780aa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
