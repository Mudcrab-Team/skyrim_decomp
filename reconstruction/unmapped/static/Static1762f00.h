// Source exposure: binary-analysis; no external implementation source reused.
// Static1762f00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762f00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762f00*);
    virtual void release(Static1762f00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762f00*);
struct Static1762f00 {
    void* value;
    Static1762f00();
    ~Static1762f00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
