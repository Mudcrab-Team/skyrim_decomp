// Source exposure: binary-analysis; no external implementation source reused.
// Static1765200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765200*);
    virtual void release(Static1765200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765200*);
struct Static1765200 {
    void* value;
    Static1765200();
    ~Static1765200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
