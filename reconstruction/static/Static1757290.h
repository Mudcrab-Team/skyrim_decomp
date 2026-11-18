// Source exposure: binary-analysis; no external implementation source reused.
// Static1757290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757290*);
    virtual void release(Static1757290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757290*);
struct Static1757290 {
    void* value;
    Static1757290();
    ~Static1757290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
