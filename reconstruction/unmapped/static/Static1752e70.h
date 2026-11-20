// Source exposure: binary-analysis; no external implementation source reused.
// Static1752e70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752e70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752e70*);
    virtual void release(Static1752e70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752e70*);
struct Static1752e70 {
    void* value;
    Static1752e70();
    ~Static1752e70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
