// Source exposure: binary-analysis; no external implementation source reused.
// Static177a240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a240*);
    virtual void release(Static177a240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a240*);
struct Static177a240 {
    void* value;
    Static177a240();
    ~Static177a240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
