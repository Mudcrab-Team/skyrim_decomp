// Source exposure: binary-analysis; no external implementation source reused.
// Static1761240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761240*);
    virtual void release(Static1761240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761240*);
struct Static1761240 {
    void* value;
    Static1761240();
    ~Static1761240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
