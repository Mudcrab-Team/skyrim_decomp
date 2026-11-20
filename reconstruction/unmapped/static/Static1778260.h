// Source exposure: binary-analysis; no external implementation source reused.
// Static1778260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778260*);
    virtual void release(Static1778260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778260*);
struct Static1778260 {
    void* value;
    Static1778260();
    ~Static1778260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
