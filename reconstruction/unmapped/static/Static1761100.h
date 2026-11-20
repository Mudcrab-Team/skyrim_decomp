// Source exposure: binary-analysis; no external implementation source reused.
// Static1761100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761100*);
    virtual void release(Static1761100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761100*);
struct Static1761100 {
    void* value;
    Static1761100();
    ~Static1761100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
