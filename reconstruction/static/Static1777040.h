// Source exposure: binary-analysis; no external implementation source reused.
// Static1777040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777040*);
    virtual void release(Static1777040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777040*);
struct Static1777040 {
    void* value;
    Static1777040();
    ~Static1777040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
