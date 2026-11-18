// Source exposure: binary-analysis; no external implementation source reused.
// Static1762280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762280*);
    virtual void release(Static1762280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762280*);
struct Static1762280 {
    void* value;
    Static1762280();
    ~Static1762280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
