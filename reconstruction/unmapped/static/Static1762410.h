// Source exposure: binary-analysis; no external implementation source reused.
// Static1762410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762410*);
    virtual void release(Static1762410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762410*);
struct Static1762410 {
    void* value;
    Static1762410();
    ~Static1762410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
