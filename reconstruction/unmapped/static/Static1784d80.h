// Source exposure: binary-analysis; no external implementation source reused.
// Static1784d80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784d80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784d80*);
    virtual void release(Static1784d80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784d80*);
struct Static1784d80 {
    void* value;
    Static1784d80();
    ~Static1784d80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
