// Source exposure: binary-analysis; no external implementation source reused.
// Static1762820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762820*);
    virtual void release(Static1762820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762820*);
struct Static1762820 {
    void* value;
    Static1762820();
    ~Static1762820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
