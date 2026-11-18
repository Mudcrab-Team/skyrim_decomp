// Source exposure: binary-analysis; no external implementation source reused.
// Static1755490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755490*);
    virtual void release(Static1755490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755490*);
struct Static1755490 {
    void* value;
    Static1755490();
    ~Static1755490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
