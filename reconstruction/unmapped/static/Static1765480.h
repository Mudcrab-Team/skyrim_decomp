// Source exposure: binary-analysis; no external implementation source reused.
// Static1765480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765480*);
    virtual void release(Static1765480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765480*);
struct Static1765480 {
    void* value;
    Static1765480();
    ~Static1765480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
