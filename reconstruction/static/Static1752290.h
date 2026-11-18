// Source exposure: binary-analysis; no external implementation source reused.
// Static1752290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752290*);
    virtual void release(Static1752290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752290*);
struct Static1752290 {
    void* value;
    Static1752290();
    ~Static1752290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
