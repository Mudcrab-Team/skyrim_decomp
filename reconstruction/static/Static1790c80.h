// Source exposure: binary-analysis; no external implementation source reused.
// Static1790c80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790c80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790c80*);
    virtual void release(Static1790c80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790c80*);
struct Static1790c80 {
    void* value;
    Static1790c80();
    ~Static1790c80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
