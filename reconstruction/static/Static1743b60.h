// Source exposure: binary-analysis; no external implementation source reused.
// Static1743b60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743b60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743b60*);
    virtual void release(Static1743b60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743b60*);
struct Static1743b60 {
    void* value;
    Static1743b60();
    ~Static1743b60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
