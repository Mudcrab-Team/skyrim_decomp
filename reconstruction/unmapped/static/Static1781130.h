// Source exposure: binary-analysis; no external implementation source reused.
// Static1781130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781130*);
    virtual void release(Static1781130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781130*);
struct Static1781130 {
    void* value;
    Static1781130();
    ~Static1781130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
