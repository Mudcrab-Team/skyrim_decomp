// Source exposure: binary-analysis; no external implementation source reused.
// Static1752600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752600*);
    virtual void release(Static1752600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752600*);
struct Static1752600 {
    void* value;
    Static1752600();
    ~Static1752600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
