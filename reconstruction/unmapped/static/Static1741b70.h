// Source exposure: binary-analysis; no external implementation source reused.
// Static1741b70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741b70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741b70*);
    virtual void release(Static1741b70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741b70*);
struct Static1741b70 {
    void* value;
    Static1741b70();
    ~Static1741b70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
