// Source exposure: binary-analysis; no external implementation source reused.
// Static1761920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761920*);
    virtual void release(Static1761920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761920*);
struct Static1761920 {
    void* value;
    Static1761920();
    ~Static1761920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
