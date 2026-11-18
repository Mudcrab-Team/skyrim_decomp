// Source exposure: binary-analysis; no external implementation source reused.
// Static1752a60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752a60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752a60*);
    virtual void release(Static1752a60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752a60*);
struct Static1752a60 {
    void* value;
    Static1752a60();
    ~Static1752a60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
