// Source exposure: binary-analysis; no external implementation source reused.
// Static1766290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766290*);
    virtual void release(Static1766290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766290*);
struct Static1766290 {
    void* value;
    Static1766290();
    ~Static1766290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
