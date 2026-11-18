// Source exposure: binary-analysis; no external implementation source reused.
// Static1755030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755030*);
    virtual void release(Static1755030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755030*);
struct Static1755030 {
    void* value;
    Static1755030();
    ~Static1755030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
