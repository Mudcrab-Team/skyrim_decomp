// Source exposure: binary-analysis; no external implementation source reused.
// Static1767c80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767c80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767c80*);
    virtual void release(Static1767c80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767c80*);
struct Static1767c80 {
    void* value;
    Static1767c80();
    ~Static1767c80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
