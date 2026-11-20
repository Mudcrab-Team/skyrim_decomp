// Source exposure: binary-analysis; no external implementation source reused.
// Static1744290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744290*);
    virtual void release(Static1744290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744290*);
struct Static1744290 {
    void* value;
    Static1744290();
    ~Static1744290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
