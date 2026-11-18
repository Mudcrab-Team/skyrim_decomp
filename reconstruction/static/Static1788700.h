// Source exposure: binary-analysis; no external implementation source reused.
// Static1788700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788700*);
    virtual void release(Static1788700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788700*);
struct Static1788700 {
    void* value;
    Static1788700();
    ~Static1788700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
