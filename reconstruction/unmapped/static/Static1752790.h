// Source exposure: binary-analysis; no external implementation source reused.
// Static1752790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752790*);
    virtual void release(Static1752790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752790*);
struct Static1752790 {
    void* value;
    Static1752790();
    ~Static1752790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
