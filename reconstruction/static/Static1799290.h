// Source exposure: binary-analysis; no external implementation source reused.
// Static1799290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799290*);
    virtual void release(Static1799290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799290*);
struct Static1799290 {
    void* value;
    Static1799290();
    ~Static1799290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
