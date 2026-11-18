// Source exposure: binary-analysis; no external implementation source reused.
// Static1751e80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751e80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751e80*);
    virtual void release(Static1751e80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751e80*);
struct Static1751e80 {
    void* value;
    Static1751e80();
    ~Static1751e80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
