// Source exposure: binary-analysis; no external implementation source reused.
// Static1751fc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751fc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751fc0*);
    virtual void release(Static1751fc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751fc0*);
struct Static1751fc0 {
    void* value;
    Static1751fc0();
    ~Static1751fc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
