// Source exposure: binary-analysis; no external implementation source reused.
// Static1787260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787260*);
    virtual void release(Static1787260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787260*);
struct Static1787260 {
    void* value;
    Static1787260();
    ~Static1787260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
