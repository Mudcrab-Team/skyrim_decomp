// Source exposure: binary-analysis; no external implementation source reused.
// Static1755260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755260*);
    virtual void release(Static1755260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755260*);
struct Static1755260 {
    void* value;
    Static1755260();
    ~Static1755260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
