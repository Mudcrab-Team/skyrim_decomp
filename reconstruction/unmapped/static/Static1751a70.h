// Source exposure: binary-analysis; no external implementation source reused.
// Static1751a70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751a70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751a70*);
    virtual void release(Static1751a70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751a70*);
struct Static1751a70 {
    void* value;
    Static1751a70();
    ~Static1751a70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
