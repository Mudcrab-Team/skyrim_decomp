// Source exposure: binary-analysis; no external implementation source reused.
// Static1743010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743010*);
    virtual void release(Static1743010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743010*);
struct Static1743010 {
    void* value;
    Static1743010();
    ~Static1743010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
