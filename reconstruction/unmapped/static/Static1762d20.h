// Source exposure: binary-analysis; no external implementation source reused.
// Static1762d20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762d20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762d20*);
    virtual void release(Static1762d20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762d20*);
struct Static1762d20 {
    void* value;
    Static1762d20();
    ~Static1762d20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
