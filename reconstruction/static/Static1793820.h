// Source exposure: binary-analysis; no external implementation source reused.
// Static1793820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793820*);
    virtual void release(Static1793820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793820*);
struct Static1793820 {
    void* value;
    Static1793820();
    ~Static1793820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
