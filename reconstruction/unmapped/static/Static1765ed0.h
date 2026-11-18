// Source exposure: binary-analysis; no external implementation source reused.
// Static1765ed0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765ed0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765ed0*);
    virtual void release(Static1765ed0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765ed0*);
struct Static1765ed0 {
    void* value;
    Static1765ed0();
    ~Static1765ed0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
