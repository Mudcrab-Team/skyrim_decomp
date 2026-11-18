// Source exposure: binary-analysis; no external implementation source reused.
// Static1760750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760750*);
    virtual void release(Static1760750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760750*);
struct Static1760750 {
    void* value;
    Static1760750();
    ~Static1760750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
