// Source exposure: binary-analysis; no external implementation source reused.
// Static1788750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788750*);
    virtual void release(Static1788750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788750*);
struct Static1788750 {
    void* value;
    Static1788750();
    ~Static1788750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
