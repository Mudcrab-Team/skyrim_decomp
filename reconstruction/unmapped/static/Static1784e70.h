// Source exposure: binary-analysis; no external implementation source reused.
// Static1784e70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784e70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784e70*);
    virtual void release(Static1784e70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784e70*);
struct Static1784e70 {
    void* value;
    Static1784e70();
    ~Static1784e70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
