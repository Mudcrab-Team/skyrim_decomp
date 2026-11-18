// Source exposure: binary-analysis; no external implementation source reused.
// Static1784240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784240*);
    virtual void release(Static1784240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784240*);
struct Static1784240 {
    void* value;
    Static1784240();
    ~Static1784240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
