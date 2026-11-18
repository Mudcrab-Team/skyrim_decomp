// Source exposure: binary-analysis; no external implementation source reused.
// Static1798290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1798290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1798290*);
    virtual void release(Static1798290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1798290*);
struct Static1798290 {
    void* value;
    Static1798290();
    ~Static1798290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
