// Source exposure: binary-analysis; no external implementation source reused.
// Static1751b60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751b60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751b60*);
    virtual void release(Static1751b60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751b60*);
struct Static1751b60 {
    void* value;
    Static1751b60();
    ~Static1751b60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
