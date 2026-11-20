// Source exposure: binary-analysis; no external implementation source reused.
// Static1751200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751200*);
    virtual void release(Static1751200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751200*);
struct Static1751200 {
    void* value;
    Static1751200();
    ~Static1751200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
