// Source exposure: binary-analysis; no external implementation source reused.
// Static1774200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774200*);
    virtual void release(Static1774200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774200*);
struct Static1774200 {
    void* value;
    Static1774200();
    ~Static1774200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
