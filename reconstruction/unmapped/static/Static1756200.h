// Source exposure: binary-analysis; no external implementation source reused.
// Static1756200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756200*);
    virtual void release(Static1756200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756200*);
struct Static1756200 {
    void* value;
    Static1756200();
    ~Static1756200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
