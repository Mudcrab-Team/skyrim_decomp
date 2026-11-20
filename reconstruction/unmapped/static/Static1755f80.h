// Source exposure: binary-analysis; no external implementation source reused.
// Static1755f80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755f80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755f80*);
    virtual void release(Static1755f80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755f80*);
struct Static1755f80 {
    void* value;
    Static1755f80();
    ~Static1755f80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
