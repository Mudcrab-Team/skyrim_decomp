// Source exposure: binary-analysis; no external implementation source reused.
// Static1757240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757240*);
    virtual void release(Static1757240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757240*);
struct Static1757240 {
    void* value;
    Static1757240();
    ~Static1757240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
