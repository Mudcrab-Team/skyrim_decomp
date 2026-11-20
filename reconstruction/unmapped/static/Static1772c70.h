// Source exposure: binary-analysis; no external implementation source reused.
// Static1772c70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772c70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772c70*);
    virtual void release(Static1772c70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772c70*);
struct Static1772c70 {
    void* value;
    Static1772c70();
    ~Static1772c70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
