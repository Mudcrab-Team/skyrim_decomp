// Source exposure: binary-analysis; no external implementation source reused.
// Static1744240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744240*);
    virtual void release(Static1744240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744240*);
struct Static1744240 {
    void* value;
    Static1744240();
    ~Static1744240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
