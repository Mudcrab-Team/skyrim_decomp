// Source exposure: binary-analysis; no external implementation source reused.
// Static1791290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1791290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1791290*);
    virtual void release(Static1791290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1791290*);
struct Static1791290 {
    void* value;
    Static1791290();
    ~Static1791290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
