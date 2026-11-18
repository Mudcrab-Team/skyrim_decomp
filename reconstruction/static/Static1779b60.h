// Source exposure: binary-analysis; no external implementation source reused.
// Static1779b60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779b60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779b60*);
    virtual void release(Static1779b60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779b60*);
struct Static1779b60 {
    void* value;
    Static1779b60();
    ~Static1779b60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
