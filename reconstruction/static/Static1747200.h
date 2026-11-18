// Source exposure: binary-analysis; no external implementation source reused.
// Static1747200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747200*);
    virtual void release(Static1747200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747200*);
struct Static1747200 {
    void* value;
    Static1747200();
    ~Static1747200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
