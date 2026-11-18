// Source exposure: binary-analysis; no external implementation source reused.
// Static1742f70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742f70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742f70*);
    virtual void release(Static1742f70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742f70*);
struct Static1742f70 {
    void* value;
    Static1742f70();
    ~Static1742f70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
