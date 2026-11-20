// Source exposure: binary-analysis; no external implementation source reused.
// Static1743240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743240*);
    virtual void release(Static1743240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743240*);
struct Static1743240 {
    void* value;
    Static1743240();
    ~Static1743240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
