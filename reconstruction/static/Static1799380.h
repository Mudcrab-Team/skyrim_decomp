// Source exposure: binary-analysis; no external implementation source reused.
// Static1799380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799380*);
    virtual void release(Static1799380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799380*);
struct Static1799380 {
    void* value;
    Static1799380();
    ~Static1799380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
