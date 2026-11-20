// Source exposure: binary-analysis; no external implementation source reused.
// Static1743290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743290*);
    virtual void release(Static1743290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743290*);
struct Static1743290 {
    void* value;
    Static1743290();
    ~Static1743290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
