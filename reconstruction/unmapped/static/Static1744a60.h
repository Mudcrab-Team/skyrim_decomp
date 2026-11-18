// Source exposure: binary-analysis; no external implementation source reused.
// Static1744a60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744a60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744a60*);
    virtual void release(Static1744a60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744a60*);
struct Static1744a60 {
    void* value;
    Static1744a60();
    ~Static1744a60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
