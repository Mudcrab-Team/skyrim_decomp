// Source exposure: binary-analysis; no external implementation source reused.
// Static1751a20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751a20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751a20*);
    virtual void release(Static1751a20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751a20*);
struct Static1751a20 {
    void* value;
    Static1751a20();
    ~Static1751a20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
