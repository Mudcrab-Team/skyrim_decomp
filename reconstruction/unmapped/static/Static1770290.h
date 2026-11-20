// Source exposure: binary-analysis; no external implementation source reused.
// Static1770290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770290*);
    virtual void release(Static1770290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770290*);
struct Static1770290 {
    void* value;
    Static1770290();
    ~Static1770290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
