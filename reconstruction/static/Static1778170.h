// Source exposure: binary-analysis; no external implementation source reused.
// Static1778170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778170*);
    virtual void release(Static1778170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778170*);
struct Static1778170 {
    void* value;
    Static1778170();
    ~Static1778170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
