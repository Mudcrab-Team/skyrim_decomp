// Source exposure: binary-analysis; no external implementation source reused.
// Static1755c10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755c10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755c10*);
    virtual void release(Static1755c10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755c10*);
struct Static1755c10 {
    void* value;
    Static1755c10();
    ~Static1755c10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
